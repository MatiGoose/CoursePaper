#include <iostream>
#include <string>
#include "register_UI.h"
#include "admin_UI.h"
#include "user_UI.h"


void menu()
{
	std::cout << "1)Просмотр истории заказов" << std::endl;
	std::cout << "1)Просмотр данных пользователя" << std::endl;
	std::cout << "2)Редактирование данных пользователя" << std::endl;
	std::cout << "3)Покупка авиабилета" << std::endl;
	std::cout << "4)Изменение пароля" << std::endl;
	std::cout << "5)Выход" << std::endl;
}

char ask_logging()
{
	std::string choice;
	std::cout << "1) Вход" << std::endl;
	std::cout << "2) Регистрация" << std::endl;
	std::cout << "3) Выход" << std::endl;
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