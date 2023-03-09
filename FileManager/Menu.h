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



//			����
// |- �������� ���������� ������ -		  1
// |- ������� �����/���� ++			      2
// |- ������� �����/���� ++				  3
// |- ������������� �����/���� ++		  4
// |- ���������� �����/���� ++			  5
// |- ��������� ������ �����/����� ++	  6
// |- ����� �� ����� � ���������� +       7
// |- ����� �� ��������	-				  8
// |- �������� ���������� �����	 +		  9
// |- �������� ���������� �����  +        10

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

	cout << "||�����/����||\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �����\n";

	return menuKey;
}

int Menu::DisplayMenuFileDirTwo() {
	menuKey = 2;

	cout << "||�����/����||\n";
	cout << "|- ����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����� <-\n";
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

	cout << "||�������������� ���������� �����||\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �������� ����������\n";
	cout << "|- �������� � �������� ����� \n";

	return menuKey;
}

int Menu::DisplayMenuEditFileTwo() {
	menuKey = 2;

	cout << "||�������������� ���������� �����||\n";
	cout << "|- �������� ����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ����� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �������� � �������� ����� \n";

	return menuKey;
}

int Menu::DisplayMenuEditFileThree() {
	menuKey = 3;

	cout << "||�������������� ���������� �����||\n";
	cout << "|- �������� ����\n";
	cout << "|- �������� �����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� � �������� ����� <-\n";
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

	cout << "\t����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���������� ������ <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayTwo() {
	menuKey = 2;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayThree() {
	menuKey = 3;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayFour() {
	menuKey = 4;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayFive() {
	menuKey = 5;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ���������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplaySix() {
	menuKey = 6;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ��������� ������ �����/����� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplaySeven() {
	menuKey = 7;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����� �� ����� � ���������� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayEight() {
	menuKey = 8;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����� �� �������� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �������� ���������� �����\n";
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayNine() {
	menuKey = 9;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���������� ����� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �������� ���������� �����\n";

	return menuKey;
}

int Menu::DisplayTen() {
	menuKey = 10;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ���������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���������� ����� <-\n";
	SetConsoleTextAttribute(hConsole, White);

	return menuKey;
}