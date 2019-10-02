#include <iostream>
#include <string>
#include "register_UI.h"
#include "admin_UI.h"
#include "user_UI.h"


void menu()
{
	std::cout << "1)�������� ������� �������" << std::endl;
	std::cout << "1)�������� ������ ������������" << std::endl;
	std::cout << "2)�������������� ������ ������������" << std::endl;
	std::cout << "3)������� ����������" << std::endl;
	std::cout << "4)��������� ������" << std::endl;
	std::cout << "5)�����" << std::endl;
}

char ask_logging()
{
	std::string choice;
	std::cout << "1) ����" << std::endl;
	std::cout << "2) �����������" << std::endl;
	std::cout << "3) �����" << std::endl;
	std::getline(std::cin, choice, '\n');
	return choice[0];
}
int main()
{
	//usUI, admUI, regUI
	setlocale(LC_ALL, "");
	int choice;
	register_UI option;
	user* current_user;
	while(true)
	{
		current_user = nullptr;
		current_user = option.get_user();
		if (current_user == NULL)
		{
			return 0;
		}
		if (current_user->get_role() == 0)
		{
			admin_UI UI;
			UI();
		}
		else
		{
			user_UI UI;
			UI(current_user);
		}
	}
}