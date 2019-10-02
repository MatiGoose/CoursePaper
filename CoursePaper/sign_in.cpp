#include "sign_in.h"
#include <string>
#include "Connection.hpp"

user * sign_in::fetch = NULL;
user* sign_in::operator()()
{
	fetch = nullptr;
	Connection connection("air_passage.sqlite3");
	auto text = form_request(ask_login_data());
	connection.Execute(text, sign_in_callback);
	if (fetch == NULL)
		throw std::string("Такого аккаунта не существует");
	return fetch;
}
int sign_in::sign_in_callback(void* user_found, int count, char** value, char** column_name)
{

	login_data log_data;
	user_data user_data;

	if (value[0] == NULL)
		return 1;
	log_data.login = value[0];
	log_data.password = value[1];
	if (value[2] == NULL)
		user_data.name = "NULL";
	else
		user_data.name = value[2];
	if (value[3] == NULL)
		user_data.surname = "NULL";
	else
		user_data.surname = value[3];
	auto role = atoi(value[4]);
	fetch = new user(log_data, user_data, role);
	return 0;
}
login_data sign_in::ask_login_data()
{

	login_data data;
	std::cout << "Введите логин: ";
	std::getline(std::cin, data.login, '\n');
	std::cout << "Введите пароль: ";
	std::getline(std::cin, data.password, '\n');
	return data;
}

std::string sign_in::form_request(login_data data)
{
	return "SELECT * FROM users WHERE login = '" + data.login + "' and password = '" + data.password + "'";
}
