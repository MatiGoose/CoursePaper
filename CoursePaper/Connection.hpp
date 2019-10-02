// ReSharper disable CppInconsistentNaming
#pragma once
#include "sqlite3.h"
#include "SQLExceptions.hpp"
#include <string>
#include <stack>

using SQLite = sqlite3;
using Callback = sqlite3_callback;


class Connection final
{
	SQLite* database;
	std::string fileName;
	std::stack<SQLException> exceptionStack;
	bool lastWasOkay;
public:
	bool LastWasOkay() const;
	std::string LastErrorMessage();
	int LastErrorCode();
	void Execute(const std::string& request);
	void Execute(const std::string& request, Callback callback);
	void Execute(const std::string& request, void* fetch);
	void Execute(const std::string& request, Callback callback, void* fetch);
	static int DefaultSelectCallback(void* fetch, int argc, char** argv, char** column);
	static void PrintSelected(char* column, char* value);
private:
	int Open();
	int Close() const;
	SQLException RaiseError(const std::string& errorMessage, const int& errorCode);
	static int DefaultCallback(void* notUsed, int argc, char** argv, char** column) { return 0; }
public:
	explicit Connection(const std::string& fileName);
	Connection(const Connection& source) = default;
	~Connection() = default;
};
