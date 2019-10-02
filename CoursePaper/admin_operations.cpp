#include "admin_operations.h"
#include "Connection.hpp"



void admin_operations::print_logins()
{
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_show_logins_request();
	connection.Execute(text, Connection::DefaultSelectCallback);
}
void admin_operations::add_login()
{
	std::string buffer[3];
	std::cout << "Введите нового пользователя" << std::endl;
	std::cout << "Роль: "<< "0 - админ, 1 - пользователь" << std::endl;
	std::getline(std::cin, buffer[2], '\n');
	while (buffer[2][0] != '0' && buffer[2][0] != '1')
	{
		std::cout << "Введите корректно" << std::endl;
		std::cout << "Роль: " << "0 - админ, 1 - пользователь" << std::endl;
		std::getline(std::cin, buffer[2], '\n');
	}
	std::cout << "Логин: ";
	std::getline(std::cin, buffer[0], '\n');
	std::cout << "Пароль: ";
	std::getline(std::cin, buffer[1], '\n');
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_insert_new_login_request(buffer[0], buffer[1], buffer[2]);
	connection.Execute(text);
}
void admin_operations::delete_login()
{
	std::string buffer;
	std::cout << "Введите логин пользователя" << std::endl;
	std::cout << "Логин: " ;
	std::getline(std::cin, buffer, '\n');
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_delete_login_request(buffer);
	connection.Execute(text);
}
void admin_operations::update_data_login()
{
	std::string buffer[3];
	std::cout << "Введите логин пользователя для редактирования" << std::endl;
	std::cout << "Логин: ";
	std::getline(std::cin, buffer[0], '\n');
	std::cout << "Имя: " ;
	std::getline(std::cin, buffer[1], '\n');
	std::cout << "Фамилия: ";
	std::getline(std::cin, buffer[2], '\n');
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_edit_data_login_request(buffer[0], buffer[1], buffer[2]);
	connection.Execute(text);

}
void admin_operations::change_password_login()
{
	std::string buffer[2];
	std::cout << "Введите логин пользователя для изменения пароля" << std::endl;
	std::cout << "Логин: ";
	std::getline(std::cin, buffer[0], '\n');
	std::cout << "Новый пароль: ";
	std::getline(std::cin, buffer[1], '\n');
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_new_password_login_request(buffer[0], buffer[1]);
	connection.Execute(text);
}
void admin_operations::print_orders()
{
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_show_orders_request();
	connection.Execute(text, Connection::DefaultSelectCallback);
}
void admin_operations::print_login_orders()
{
	std::string buffer;
	std::cout << "Введите логин пользователя" << std::endl;
	std::cout << "Логин: ";
	std::getline(std::cin, buffer, '\n');
	std::string text;
	Connection connection("air_passage.sqlite3");
	text = form_login_orders_request(buffer);
	connection.Execute(text, Connection::DefaultSelectCallback);
}


std::string admin_operations::form_edit_data_login_request(std::string login, std::string name, std::string surname)
{
	return "update users set name = '" + name + "', surname = '" + surname + "' where login = '" + login + "'";
}
std::string admin_operations::form_delete_login_request(std::string login)
{
	return "delete from users where login = '" + login + "'";
}
std::string admin_operations::form_insert_new_login_request(std::string login, std::string password, std::string role)
{
	return "insert into users (login, password, role) values('" + login + "', '" + password + "', " + role + ")";
}
std::string admin_operations::form_new_password_login_request(std::string login, std::string password)
{
	return "update users set password = '" + password + "' where login = '" + login + "'";
}
std::string admin_operations::form_show_logins_request()
{
	return "select * from users";
}
std::string admin_operations::form_show_orders_request()
{
	return "select * from orders";
}
std::string admin_operations::form_login_orders_request(std::string login)
{
	return "select date, duration, from_adr, to_adr, price from orders where login = '" + login + "'";
}