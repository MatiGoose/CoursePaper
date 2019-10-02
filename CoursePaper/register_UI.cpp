#include "register_UI.h"
#include "sign_in.h"
#include "sign_up.h"
#include <string>


void register_UI::menu()
{
	system("cls");
	std::cout << "1)�����" << std::endl;
	std::cout << "2)���������������� ����� ������� ������" << std::endl;
	std::cout << "3)�����" << std::endl;
}
user* register_UI::get_user()
{
	std::string choice;
	sign_in logging;
	sign_up registration;
	while (true)
	{
		try
		{
			menu();
			std::getline(std::cin, choice, '\n');
			switch (choice[0])
			{
			case '1':
				return logging();
				break;
			case '2':
				return registration();
				break;
			case '3':
				return NULL;
				break;
			default:
				break;
			}
		}
		catch (std::string message)
		{
			std::cout << message << std::endl;
		}
		catch (...)
		{
			std::cout << "������� ��� ����������" << std::endl;
		}
	}
}