#include "user.h"
#include "sign_in.h"
#include "order.h"
#include "user.h"
#include <string>
#pragma once



class admin_operations
{
public:
	void print_logins();
	void add_login();
	void delete_login();
	void update_data_login();
	void change_password_login();
	void print_orders();
	void print_login_orders();

private:
	std::string form_insert_new_login_request(std::string login, std::string password, std::string role);
	std::string form_edit_data_login_request(std::string login, std::string name, std::string surname);
	std::string form_new_password_login_request(std::string login, std::string password);
	std::string form_delete_login_request(std::string login);
	std::string form_login_orders_request(std::string login);
	std::string form_show_logins_request();
	std::string form_show_orders_request();
};