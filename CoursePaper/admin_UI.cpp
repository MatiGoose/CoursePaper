#include "admin_UI.h"
#include "admin_operations.h"
#include <conio.h>

void admin_UI::menu()
{
	system("cls");
	std::cout << "1)����������� ������� ������" << std::endl;
	std::cout << "2)�������� ������������" << std::endl;
	std::cout << "3)������� ������������" << std::endl;
	std::cout << "4)�������� ������ ������������" << std::endl;
	std::cout << "5)�������� ������ ������������" << std::endl;
	std::cout << "6)����������� ��� ������" << std::endl;
	std::cout << "7)����������� ������ ������������" << std::endl;
	std::cout << "8)����� �� ������� ������" << std::endl;
}
void admin_UI::operator()()
{
	std::string choice;
	admin_operations operations;
	while (true)
	{
		menu();
		std::getline(std::cin, choice, '\n');
		switch (choice[0])
		{
		case '1':
			operations.print_logins();
			std::cout << "������� ������� ��� �����������" << std::endl;
			getch();
			break;
		case '2':
			operations.add_login();
			break;
		case '3':
			operations.delete_login();
			break;
		case '4':
			operations.update_data_login();
			break;
		case '5':
			operations.change_password_login();
			break;
		case '6':
			operations.print_orders();
			std::cout << "������� ������� ��� �����������" << std::endl;
			getch();
			break;
		case '7':
			operations.print_login_orders();
			std::cout << "������� ������� ��� �����������" << std::endl;
			getch();
			break;
		case '8':
			return;
			break;
		default:
			std::cout << "������� ���������!" << std::endl;
			break;
		}
	}
}