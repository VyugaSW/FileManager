#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;


HANDLE hConsole;
enum ColorConsole { White = 7, Blue = 3};
int menuKey;


//			����
// |- �������� ���������� ������		 1
// |- ������� �����/����			     2
// |- ������� �����/���� +				 3
// |- ������������� �����/���� +		 4
// |- ����������, ��������� �����/���� + 5
// |- ��������� ������ �����/����� +	 6
// |- ����� �� ����� � ���������� +	     7
// |- ����� �� ��������					 8
// |- �������� ���������� �����			 9

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

	cout << "\t����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���������� ������ <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayTwo() {
	menuKey = 50;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayThree() {
	menuKey = 51;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayFour() {
	menuKey = 52;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ������������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayFive() {
	menuKey = 53;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����������, ��������� �����/���� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplaySix() {
	menuKey = 54;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ��������� ������ �����/����� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplaySeven() {
	menuKey = 55;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����� �� ����� � ���������� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- ����� �� ��������\n";
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayEight() {
	menuKey = 56;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- ����� �� �������� <-\n";
	SetConsoleTextAttribute(hConsole, White);
	cout << "|- �������� ���������� �����\n";


	return menuKey;
}

int DisplayNine() {
	menuKey = 57;

	cout << "\t����\n";
	cout << "|- �������� ���������� ������\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������� �����/����\n";
	cout << "|- ������������� �����/����\n";
	cout << "|- ����������, ��������� �����/����\n";
	cout << "|- ��������� ������ �����/�����\n";
	cout << "|- ����� �� ����� � ����������\n";
	cout << "|- ����� �� ��������\n";
	SetConsoleTextAttribute(hConsole, Blue);
	cout << "|- �������� ���������� ����� <-\n";
	SetConsoleTextAttribute(hConsole, White);


	return menuKey;
}