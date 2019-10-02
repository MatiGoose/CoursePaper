#pragma once
#include "UI.h"

class user_UI : public UI
{
public:
	void menu();
	virtual void operator()(user * us);
	void operator()() {};
	virtual ~user_UI() = default;
};