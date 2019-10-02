#include "user.h"
#pragma once


class sign_in
{
	static user* fetch;
public:
	user* operator()();
	login_data ask_login_data();
	std::string form_request(login_data data);
	static int sign_in_callback(void* user_found, int count, char** value, char** column_name);
	sign_in() {};
	~sign_in() = default;
};