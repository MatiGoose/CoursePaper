#pragma once
#include "UI.h"

class admin_UI : public UI
{
public:
	void menu();
	virtual void operator()();
	virtual ~admin_UI() = default;
};