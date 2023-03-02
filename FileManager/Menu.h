#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;


HANDLE hConsole;
enum ColorConsole { White = 7, Blue = 3};
int menuKey;


//			МЕНЮ
// |- Показать содержимое дисков		 1
// |- Создать папку/файл			     2
// |- Удалить папку/файл +				 3
// |- Переименовать папку/файл +		 4
// |- Копировать, перенести папку/файл + 5
// |- Вычислить размер папки/файла +	 6
// |- Поиск по маске с подпадками +	     7
// |- Поиск по названию					 8
// |- Изменить содержимое файла			 9

int DisplayOne();
int DisplayTwo();
int DisplayThree();
int DisplayFour();
int DisplayFive();
int DisplaySix();
int DisplaySeven();
int DisplayEight();
int DisplayNine();

int DisplayMenu() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int userKey;

	DisplayOne();

	while(true) {
		
		userKey = _getch();
		userKey = _getch();

		// Menu coordination
		if (userKey == 80 && menuKey < 57)
			menuKey++;
		else if (userKey == 72 && menuKey > 49)
			menuKey--;

		// Exception in menu coordination
		else if (userKey == 80 && menuKey == 57)
			menuKey = 49;
		else if (userKey == 72 && menuKey == 49)
			menuKey = 57;

		// Exit from menu to do a task
		else if (userKey == 13)
			// Return a task number in menu (its code)
			return menuKey;

		// Exit from programme
		else if (userKey == 27)
			return 0;

		system("cls");
		switch (menuKey) {
		case 49:
			DisplayOne();
			break;
		case 50:
			DisplayTwo();
			break;
		case 51:
			DisplayThree();
			break;
		case 52:
			DisplayFour();
			break;
		case 53:
			DisplayFive();
			break;
		case 54:
			DisplaySix();
			break;
		case 55:
			DisplaySeven();
			break;
		case 56:
			DisplayEight();
			break;
		case 57:
			DisplayNine();
			break;
		}
	}
}

int DisplayOne() {
	menuKey = 49;

	cout << "\tМЕНЮ\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Показать содержимое дисков <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayTwo() {
	menuKey = 50;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Создать папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayThree() {
	menuKey = 51;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Удалить папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayFour() {
	menuKey = 52;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Переименовать папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayFive() {
	menuKey = 53;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Копировать, перенести папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplaySix() {
	menuKey = 54;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Вычислить размер папки/файла <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplaySeven() {
	menuKey = 55;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Поиск по маске с подпадками <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayEight() {
	menuKey = 56;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Поиск по названию <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Изменить содержимое файла\n";


	return menuKey;
}

int DisplayNine() {
	menuKey = 57;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать, перенести папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Изменить содержимое файла <-\n";
	SetConsoleTextAttribute(hConsole, White);


	return menuKey;
}