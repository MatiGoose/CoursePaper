#pragma once
#include <exception>
#include <string>


class SQLException : public std::exception
{
protected:
	std::string errorMessage;
	int errorCode;
public:
	std::string LastErrorMessage() const noexcept;
	int LastErrorCode() const noexcept;
	char const* what() const noexcept override;
	SQLException(const std::string& errorMessage, const int& codeError) noexcept;
	SQLException(const SQLException& source) noexcept;
	~SQLException() noexcept = default;
};
