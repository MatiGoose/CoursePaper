#include "user_UI.h"
#include <conio.h>
#include "passenger_operations.h"


void user_UI::menu()
{
	system("cls");
	std::cout << "1)Редактировать профиль" << std::endl;
	std::cout << "2)Изменить пароль" << std::endl;
	std::cout << "3)Купить билет" << std::endl;
	std::cout << "4)Просмотреть историю заказов" << std::endl;
	std::cout << "5)Выход из учетной записи" << std::endl;
}
void user_UI::operator()(user * us)
{
	std::string choice;
	passenger_operations operations(us);
	while (true)
	{
		menu();
		std::getline(std::cin, choice, '\n');
		switch (choice[0])
		{
		case '1':
			operations.edit_data();
			break;
		case '2':
			operations.change_password();
			break;
		case '3':
			operations.buy_ticket();
			std::cout << "Нажмите клавишу для продолжения" << std::endl;
			getch();
			break;
		case '4':
			operations.print_orders();
			std::cout << "Нажмите клавишу для продолжения" << std::endl;
			getch();
			break;
		case '5':
			return;
			break;
		default:
			std::cout << "Введите корректно!" << std::endl;
			break;
		}


	}
}