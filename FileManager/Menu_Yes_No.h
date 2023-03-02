#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>

using namespace std;




HANDLE hConsole_;
enum ColorConsole_ { White_ = 7, Blue_ = 3 };
int menuKey_;

int DisplayYes();
int DisplayNo();


int DisplayYesNo() {
	hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);

	int userKey;

	DisplayYes();

	while (true) {

		userKey = _getch();
		userKey = _getch();

		//Menu coordination
		if (userKey == 80 && menuKey_ == 2)
			menuKey_ = 1;
		else if (userKey == 72 && menuKey_ == 1)
			menuKey_ = 2;
		else if (userKey == 80 && menuKey_ == 1)
			menuKey_ = 2;
		else if (userKey == 72 && menuKey_ == 2)
			menuKey_ = 1;

		// Exit from menu to do a task
		else if (userKey == 13)
			// Return a task number in menu
			return menuKey_;

		system("cls");
		switch (menuKey_) {
		case 1:
			DisplayYes();
			break;
		case 2:
			DisplayNo();
			break;
		}
	}
}



int DisplayYes() {
	menuKey_ = 1;

	SetConsoleTextAttribute(hConsole_, Blue_);
	cout << "|- Да <-\n";
	SetConsoleTextAttribute(hConsole_, White_);
	cout << "|- Нет\n";

	return menuKey_;
}

int DisplayNo() {
	menuKey_ = 2;

	cout << "|- Да\n";
	SetConsoleTextAttribute(hConsole_, Blue_);
	cout << "|- Нет <-\n";
	SetConsoleTextAttribute(hConsole_, White_);
	return menuKey_;
}