#pragma once
#include <iostream>
#include <map>

const int ADMIN = 0;
const int PASSENGER = 1;
struct login_data
{
	std::string login;
	std::string password;
};
struct user_data
{
	std::string name;
	std::string surname;
	friend std::ostream& operator<< (std::ostream& stream, const user_data& out);
};
class user final
{
	login_data logging;
	user_data data;
	int role;
public:
	std::string get_login(){return logging.login;}
	user_data get_data(){return data;}
	int get_role(){return role;}

	static std::map<int, std::string> role_map;

	friend std::ostream& operator<< (std::ostream& stream, const user& out);
	user(const login_data& data, const user_data& credits, const int& role);
	~user() = default;
};