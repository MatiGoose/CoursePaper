// ReSharper disable CppInconsistentNaming
#include "Connection.hpp"
#include <iostream>
#include <map>

void Connection::Execute(const std::string& request)
{
	char* errorMessage = nullptr;
	Open();
	auto response = sqlite3_exec(database, request.c_str(), DefaultCallback, nullptr, &errorMessage);
	Close();
	if (response != 0)
		throw RaiseError(errorMessage, response);
	lastWasOkay = true;
}

void Connection::Execute(const std::string& request, Callback callback)
{
	char* errorMessage = nullptr;
	Open();
	auto response = sqlite3_exec(database, request.c_str(), callback, nullptr, &errorMessage);
	Close();
	if (response != 0)
		throw RaiseError(errorMessage, response);
	lastWasOkay = true;
}

void Connection::Execute(const std::string& request, void* fetch)
{
	char* errorMessage = nullptr;
	Open();
	auto response = sqlite3_exec(database, request.c_str(), DefaultCallback, fetch, &errorMessage);
	Close();
	if (response != 0)
		throw RaiseError(errorMessage, response);
	lastWasOkay = true;
}

void Connection::Execute(const std::string& request, Callback callback, void* fetch)
{
	char* errorMessage = nullptr;
	Open();
	auto response = sqlite3_exec(database, request.c_str(), callback, fetch, &errorMessage);
	Close();
	if (response != 0)
		throw RaiseError(errorMessage, response);
	lastWasOkay = true;
}

int Connection::Open()
{
	return sqlite3_open(fileName.c_str(), &database);
}

int Connection::Close() const
{
	return sqlite3_close(database);
}

SQLException Connection::RaiseError(const std::string& errorMessage, const int& errorCode)
{
	lastWasOkay = false;
	auto newException = SQLException(errorMessage, errorCode);
	exceptionStack.push(newException);
	return newException;
}

bool Connection::LastWasOkay() const
{
	return lastWasOkay;
}

std::string Connection::LastErrorMessage()
{
	if (!exceptionStack.empty())
		return exceptionStack.top().LastErrorMessage();
	return "";
}

int Connection::LastErrorCode()
{
	if (!exceptionStack.empty())
		return exceptionStack.top().LastErrorCode();
	return EXIT_SUCCESS;
}

Connection::Connection(const std::string& fileName) : fileName(fileName)
{
	database = nullptr;
	lastWasOkay = true;
}

int Connection::DefaultSelectCallback(void* fetch, int argc, char** argv, char** column)
{
	std::map<int, std::string> role_map = { {0, "Role: Admin"},{1, "Role: User"} };
	for (auto i = 0; i != argc; ++i)
	{
		if (strcmp(column[i], "role") == 0)
		{
			std::cout << role_map[atoi(argv[i])] << std::endl;
			continue;
		}
		PrintSelected(column[i], argv[i]);
	}
	return EXIT_SUCCESS;
}

void Connection::PrintSelected(char* column, char* value)
{
	std::cout << column << ": ";
	value == nullptr ? std::cout << "NULL" : std::cout << value;
	std::cout << std::endl;
}
