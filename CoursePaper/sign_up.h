#pragma once

#include "user.h"
#pragma once


class sign_up
{
	static user* fetch;
public:
	user* operator()();
	login_data ask_login_data();
	user_data ask_user_data();
	std::string form_request(login_data data, user_data user_data);

	sign_up() {};
	~sign_up() = default;
};