#pragma once
#include "user.h"
class UI
{
public:
	virtual void operator()() = 0;
	virtual ~UI() = default;
};