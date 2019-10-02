#include "sign_up.h"
#include <string>
#include "Connection.hpp"


user* sign_up::operator()()
{
	Connection connection("air_passage.sqlite3");
	auto log_data = ask_login_data();
	auto use_data = ask_user_data();
	auto text = form_request(log_data, use_data);
	connection.Execute(text);
	return new user(log_data, use_data, PASSENGER);
}

login_data sign_up::ask_login_data()
{

	login_data data;
	std::cout << "¬ведите логин: ";
	std::getline(std::cin, data.login, '\n');
	std::cout << "¬ведите пароль: ";
	std::getline(std::cin, data.password, '\n');
	return data;
}
user_data sign_up::ask_user_data()
{
	user_data data;
	std::cout << "¬ведите им€: ";
	std::getline(std::cin, data.name, '\n');
	std::cout << "¬ведите фамилию: ";
	std::getline(std::cin, data.surname, '\n');
	return data;
}

std::string sign_up::form_request(login_data data, user_data user_data)
{
	return "INSERT INTO users (login, password, name, surname, role) " \
		"VALUES ('" + data.login + "', '" + data.password + "', '" + user_data.name + "', '" + user_data.surname + "', 1)";
}
