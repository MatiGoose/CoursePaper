#pragma once
#include<iostream>
#include "user.h"
#include <map>

struct order_info
{
	std::string date;
	std::string from;
	std::string to;
	std::string duration;
	int order_id;
	int price;
	friend std::ostream& operator << (std::ostream& stream, const order_info& out);
	friend std::istream& operator >> (std::istream& stream, order_info& in);
};

class order final
{
	order_info ord_info;
	user_data data;
public:
	order_info get_order_info() { return ord_info; }
	order(const user_data& passenger, const order_info& info);
	~order() = default;
	friend std::ostream& operator << (std::ostream& stream, const order& out);
};