#include "user.h"
#include "sign_in.h"
#include "order.h"
#include <string>
#pragma once



class passenger_operations
{
	user us;
	order_info order;
public:
	passenger_operations(user * us);
	void edit_data();
	void change_password();
	void buy_ticket();
	void print_orders();
private:
	std::string form_surname_request(std::string login, std::string us_surname);
	std::string form_name_and_surname_request(std::string login, std::string us_name, std::string us_surname);
	std::string form_name_request(std::string login, std::string us_name);
	std::string form_password_request(std::string login, std::string us_password);
	std::string form_order_request(std::string login, order_info order);
	std::string form_show_orders_request(std::string login);
};