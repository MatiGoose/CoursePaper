#include "user.h"
#include "order.h"
#include <iostream>
#include <iomanip>

std::ostream& operator<<(std::ostream& stream, const user_data& out)
{
	stream << out.name << " " << out.surname;
	return stream;
}
std::ostream& operator<<(std::ostream& stream, const user& out)
{
	stream << out.data << ", " << user::role_map[out.role] << std::endl;
	return stream;
}
user::user(const login_data& data, const user_data& credits, const int& role)
{
	logging = data;
	this->data = credits;
	this->role = role;
}
std::map<int, std::string> user::role_map = {
	{ADMIN, "an admin"},
	{PASSENGER, "a passenger"}
};