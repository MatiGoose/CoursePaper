#include "passenger_operations.h"
#include "Connection.hpp"
#include <string>

passenger_operations::passenger_operations(user* us) :us(*us) {}
void passenger_operations::edit_data()
{
	std::cout << "1)Редактировать Имя" << std::endl;
	std::cout << "2)Редактировать Фамилию" << std::endl;
	std::cout << "3)Редактировать все данные" << std::endl;
	std::string choice;
	std::string name;
	std::string surname; 
	std::string text;
	std::getline(std::cin, choice, '\n');
	Connection connection("air_passage.sqlite3");
	while (choice.c_str()[0] != '1' && choice.c_str()[0] != '2' && choice.c_str()[0] != '3')
	{
		switch (choice.c_str()[0])
		{
		case '1':
			system("cls");
			std::cout << "Введите Имя" << std::endl;
			std::getline(std::cin, name, '\n');
			text = form_name_request(us.get_login(), name);
			break;
		case '2':
			system("cls");
			std::cout << "Введите Фамилию" << std::endl;
			std::getline(std::cin, surname, '\n');
			text = form_surname_request(us.get_login(), surname);
			break;
		case '3':
			system("cls");
			std::cout << "Введите Имя" << std::endl;
			std::getline(std::cin, name, '\n');
			std::cout << "Введите Фамилию" << std::endl;
			std::getline(std::cin, surname, '\n');
			text = form_name_and_surname_request(us.get_login(), name, surname);
			break;
		default:
			std::cout << "Введите корректно!" << std::endl;
			break;
		}
	}
	connection.Execute(text);
	return ;
}
void passenger_operations::change_password()
{
	std::string password;
	std::string text;
	std::string choice;
	std::cout << "Введите новый пароль: " << std::endl;
	std::getline(std::cin, choice, '\n');
	Connection connection("air_passage.sqlite3");
	text = form_name_request(us.get_login(), password);
	connection.Execute(text);

}
void passenger_operations::buy_ticket()
{
	std::cin >> order;
	Connection connection("air_passage.sqlite3");
	std::string text = form_order_request(us.get_login(), order);
	connection.Execute(text);

}
void passenger_operations::print_orders()
{
	Connection connection("air_passage.sqlite3");
	std::string text = form_show_orders_request(us.get_login());
	connection.Execute(text, Connection::DefaultSelectCallback);

}


std::string passenger_operations::form_password_request(std::string login, std::string us_password)
{
	return "update users set password = '" + us_password + "' where login = '" + login + "'";
}
std::string passenger_operations::form_name_request(std::string login, std::string us_name)
{
	return "update users set name = '" + us_name + "' where login = '" + login + "'";
}
std::string passenger_operations::form_surname_request(std::string login, std::string us_surname)
{
	return "update users set surname = '" + us_surname + "' where login = '" + login + "'";
}
std::string passenger_operations::form_name_and_surname_request(std::string login, std::string us_name, std::string us_surname)
{
	return "update users set name = '" + us_name + "', surname = '" + us_surname + "' where login = '" + login + "'";
}
std::string passenger_operations::form_order_request(std::string login, order_info order)
{
	return "insert into orders (date, duration, from_adr, to_adr, price, login) values('" + order.date + "', '" + order.duration + "', '" + order.from + "', '" + order.to + "', " + std::to_string(order.price) + ", '" + login +"')";
}
std::string passenger_operations::form_show_orders_request(std::string login)
{
	return "select date, duration, from_adr, to_adr, price from orders where login = '" + login + "'";
}
