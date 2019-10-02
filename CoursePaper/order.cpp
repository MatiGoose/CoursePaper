#include "order.h"
#include <iostream>
#include <string>
#include <ctime>


std::ostream& operator<<(std::ostream& stream, const order_info& out)
{
	stream << "Form " << out.from << " to " << out.to << std::endl;
	stream << "Date: " << out.date << ", duration: " << out.duration;
	stream << "Cost: " << out.price << std::endl;
	return stream;
}
order::order(const user_data& passenger, const order_info& info) :
	data(passenger), ord_info(info) { }

std::ostream& operator << (std::ostream& stream, const order& out)
{
	stream << "Passenger " << out.data << std::endl;
	stream << out.ord_info;
	return stream;
}
std::istream& operator >> (std::istream& stream, order_info& in)
{
	std::string year, month, day;
	std::string addressFrom, addressTo;
	int price, duration;	
	int hours, minutes;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::cout << "√од: ";
	std::getline(stream, year, '\n');
	while (std::stoi(year) < 2017 || std::stoi(year) > 2025)
	{
		std::cout << "¬ведите год в промежутке 2017 - 2025!" << std::endl;
		std::cout << "√од: ";
		std::getline(stream, year, '\n');
	}
	std::cout << "ћес€ц: ";
	std::getline(stream, month, '\n');
	while (std::stoi(month) < 1 || std::stoi(month) > 12)
	{
		std::cout << "¬ведите мес€ц в промежутке 1 - 12!" << std::endl;
		std::cout << "ћес€ц: ";
		std::getline(stream, month, '\n');
	}
	int max_day = days[stoi(month) - 1];
	std::cout << "ƒень: ";
	std::getline(stream, day, '\n');
	while (std::stoi(day) < 1 || std::stoi(day) > max_day)
	{
		std::cout << "¬ведите день в промежутке 1 - "<< max_day << "!" << std::endl;
		std::cout << "ƒень: ";
		std::getline(stream, day, '\n');
	}
	std::cout << "ќткуда: ";
	std::getline(stream, addressFrom, '\n');
	std::cout << " уда: ";
	std::getline(stream, addressTo, '\n');
	srand(time(0));
	std::cout << "÷ена: ";
	price = 100 + rand() % 1000;
	std::cout << price << "$" << std::endl;
	std::cout << "ƒлительность полЄта: ";
	duration = 60 + rand() % 300;
	hours = duration / 60;
	minutes = duration - hours * 60;
	std::cout << hours << " часов " << minutes << " минут" << std::endl;
	in.date = day + "." + month + "." + year;
	in.duration = std::to_string(hours) + " ч, " + std::to_string(minutes) + " м";
	in.from = addressFrom;
	in.to = addressTo;
	in.price = price;
	return stream;

}
