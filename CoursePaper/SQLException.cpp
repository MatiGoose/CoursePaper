#include "SQLExceptions.hpp"


int SQLException::LastErrorCode() const noexcept
{
	return errorCode;
}

std::string SQLException::LastErrorMessage() const noexcept
{
	return errorMessage;
}

char const* SQLException::what() const noexcept
{
	auto what_ = "Error " + std::to_string(errorCode) + " occured: " + errorMessage;
	return what_.c_str();
}

SQLException::SQLException(const std::string& errorMessage, const int& codeError) noexcept :
	errorMessage(errorMessage), errorCode(codeError) { }

SQLException::SQLException(const SQLException& source) noexcept :
	SQLException(source.errorMessage, source.errorCode) { }


