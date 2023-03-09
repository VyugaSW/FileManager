#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Menu {
	HANDLE hConsole;
	enum ColorConsole { White = 7, Blue = 3 };
	int menuKey;

	int DisplayOne();
	int DisplayTwo();
	int DisplayThree();
	int DisplayFour();
	int DisplayFive();
	int DisplaySix();
	int DisplaySeven();
	int DisplayEight();
	int DisplayNine();
	int DisplayTen();

	int DisplayMenuEditFileOne();
	int DisplayMenuEditFileTwo(); 
	int DisplayMenuEditFileThree();

	int DisplayMenuFileDirOne();
	int DisplayMenuFileDirTwo();
public:
	int DisplayMenu();
	int DisplayMenuFileDir();
	int DisplayMenuEditFile();
};



//			МЕНЮ
// |- Показать содержимое дисков -		  1
// |- Создать папку/файл ++			      2
// |- Удалить папку/файл ++				  3
// |- Переименовать папку/файл ++		  4
// |- Копировать папку/файл ++			  5
// |- Вычислить размер папки/файла ++	  6
// |- Поиск по маске с подпадками +       7
// |- Поиск по названию	-				  8
// |- Изменить содержимое файла	 +		  9
// |- Показать содержимое файла  +        10

int Menu::DisplayMenuFileDir() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int userKey;

	DisplayMenuFileDirOne();

	while (true) {

		userKey = _getch();
		if(userKey != 13)
			userKey = _getch();

		// Menu coordination
		if (userKey == 80 && menuKey == 2)
			menuKey = 1;
		else if (userKey == 72 && menuKey == 1)
			menuKey = 2;
		else if (userKey == 80 && menuKey == 1)
			menuKey = 2;
		else if (userKey == 72 && menuKey == 2)
			menuKey = 1;

		// Exit from menu to do a task
		else if (userKey == 13)
			// Return a task number in menu (its code)
			return menuKey;

		// Exit from programme
		else if (userKey == 27)
			return 0;

		system("cls");
		switch (menuKey) {
		case 1:
			DisplayMenuFileDirOne();
			break;
		case 2:
			DisplayMenuFileDirTwo();
			break;
		}
	}
}

int Menu::DisplayMenuFileDirOne() {
	menuKey = 1;

	cout << "||ПАПКА/ФАЙЛ||\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Папка\n";

	return menuKey;
}

int Menu::DisplayMenuFileDirTwo() {
	menuKey = 2;

	cout << "||ПАПКА/ФАЙЛ||\n";
	cout << "|- Файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Папка <-\n";
	SetConsoleTextAttribute(hConsole, White);

	return menuKey;
}



int Menu::DisplayMenuEditFile() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int userKey;

	DisplayMenuEditFileOne();

	while (true) {

		userKey = _getch();
		if (userKey != 13)
			userKey = _getch();

		// Menu coordination
		if (userKey == 80 && menuKey < 3)
			menuKey++;
		else if (userKey == 72 && menuKey > 1)
			menuKey--;

		// Exception in menu coordination
		else if (userKey == 80 && menuKey == 3)
			menuKey = 1;
		else if (userKey == 72 && menuKey == 1)
			menuKey = 3;

		// Exit from menu to do a task
		else if (userKey == 13)
			// Return a task number in menu (its code)
			return menuKey;

		// Exit from programme
		else if (userKey == 27)
			return 0;

		system("cls");
		switch (menuKey) {
		case 1:
			DisplayMenuEditFileOne();
			break;
		case 2:
			DisplayMenuEditFileTwo();
			break;
		case 3:
			DisplayMenuEditFileThree();
			break;
		}
	}
}

int Menu::DisplayMenuEditFileOne() {
	menuKey = 1;

	cout << "||РЕДАКТИРОВАНИЕ ТЕКСТОВОГО ФАЙЛА||\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Очистить файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Изменить информацию\n";
	cout << "|- Очистить и записать текст \n";

	return menuKey;
}

int Menu::DisplayMenuEditFileTwo() {
	menuKey = 2;

	cout << "||РЕДАКТИРОВАНИЕ ТЕКСТОВОГО ФАЙЛА||\n";
	cout << "|- Очистить файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Добавить текст <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Очистить и записать текст \n";

	return menuKey;
}

int Menu::DisplayMenuEditFileThree() {
	menuKey = 3;

	cout << "||РЕДАКТИРОВАНИЕ ТЕКСТОВОГО ФАЙЛА||\n";
	cout << "|- Очистить файл\n";
	cout << "|- Добавить текст\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Очистить и записать текст <-\n";
	SetConsoleTextAttribute(hConsole, White);

	return menuKey;
}



int Menu::DisplayMenu() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int userKey;

	DisplayOne();

	while(true) {
		
		userKey = _getch();
		if (userKey != 13)
			userKey = _getch();

		// Menu coordination
		if (userKey == 80 && menuKey < 10)
			menuKey++;
		else if (userKey == 72 && menuKey > 1)
			menuKey--;

		// Exception in menu coordination
		else if (userKey == 80 && menuKey == 10)
			menuKey = 1;
		else if (userKey == 72 && menuKey == 1)
			menuKey = 10;

		// Exit from menu to do a task
		else if (userKey == 13)
			// Return a task number in menu (its code)
			return menuKey;

		// Exit from programme
		else if (userKey == 27)
			return 0;

		system("cls");
		switch (menuKey) {
		case 1:
			DisplayOne();
			break;
		case 2:
			DisplayTwo();
			break;
		case 3:
			DisplayThree();
			break;
		case 4:
			DisplayFour();
			break;
		case 5:
			DisplayFive();
			break;
		case 6:
			DisplaySix();
			break;
		case 7:
			DisplaySeven();
			break;
		case 8:
			DisplayEight();
			break;
		case 9:
			DisplayNine();
			break;
		case 10:
			DisplayTen();
			break;
		}
	}
}

int Menu::DisplayOne() {
	menuKey = 1;

	cout << "\tМЕНЮ\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Показать содержимое дисков <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayTwo() {
	menuKey = 2;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Создать папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayThree() {
	menuKey = 3;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Удалить папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayFour() {
	menuKey = 4;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Переименовать папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayFive() {
	menuKey = 5;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Копировать папку/файл <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplaySix() {
	menuKey = 6;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Вычислить размер папки/файла <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplaySeven() {
	menuKey = 7;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Поиск по маске с подпадками <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayEight() {
	menuKey = 8;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Поиск по названию <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Изменить содержимое файла\n";
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayNine() {
	menuKey = 9;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Изменить содержимое файла <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- Показать содержимое файла\n";

	return menuKey;
}

int Menu::DisplayTen() {
	menuKey = 10;

	cout << "\tМЕНЮ\n";
	cout << "|- Показать содержимое дисков\n";
	cout << "|- Создать папку/файл\n";
	cout << "|- Удалить папку/файл\n";
	cout << "|- Переименовать папку/файл\n";
	cout << "|- Копировать папку/файл\n";
	cout << "|- Вычислить размер папки/файла\n";
	cout << "|- Поиск по маске с подпадками\n";
	cout << "|- Поиск по названию\n";
	cout << "|- Изменить содержимое файла\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- Показать содержимое файла <-\n";
	SetConsoleTextAttribute(hConsole, White);

	return menuKey;
}