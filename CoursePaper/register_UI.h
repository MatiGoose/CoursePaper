#pragma once
#include "UI.h"
#include "user.h"

class register_UI : public UI
{
public:
	void menu();
	user* get_user(); // reg or log
	void operator()() {};
	virtual ~register_UI() = default;
};
