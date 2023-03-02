

#include <iostream>
#include <cstdlib>
#include <conio.h>;
#include <Windows.h>
#include <io.h>
#include <stdio.h>


#include "Menu.h"
#include "Menu_Yes_No.h"
#include "Exceptions.h"

using namespace std;


void RenameFile() {
	system("cls");
	char* oldName = new char[_MAX_PATH];
	char* newName = new char[_MAX_PATH];


	cout << "Введите старое имя файла: "; cin >> oldName;
	//%
	if (_access(oldName, 00) == -1) {
		cout << "\tУказан неверный путь к файлу или его название\n";
		Sleep(1500);
		return;
	}

	cout << "Введите новое имя файла: "; cin >> newName;
	
	if (rename(oldName, newName) != 0)
		cout << "Ошибка!\n Файл не был переименован\n";
	else
		cout << "Файл успешно переименован!";

	Sleep(1500);
}



bool CopyFile_check(char* source, char* destination) {
	if (_access(destination, 00) == -1) {
		cout << "Файл с таким именем уже создан.\n Перезаписать?\n";
		int answer = DisplayYesNo();
		if (answer == 2) {
			cout << "Операция отменена\n";
			return false;
		}
		else if (answer == 1) {
			if (_access(destination, 02) == -1 && _access(destination, 00) == 0) {
				cout << "Нет доступа к записи";
				return false;
			}
		}
	}
	
	return true;
}

void CopyFile_() {
	system("cls");
	const int size = 65536;

	char* source = new char[_MAX_PATH];
	char* destination = new char[_MAX_PATH];
	
	cout << "Введите путь и название копируемого файла: "; cin >> source;
	//%
	if (_access(source, 00) == -1) {
		cout << "\tУказан неверный путь к файлу или его название\n";
		Sleep(1500);
		return;
	}

	cout << "Введите путь и название нового файла: "; cin >> destination;


	if (!CopyFile_check(source, destination)) {
		Sleep(1500);
		return;
	}

	bool flag = true;
	FILE *scr, * dst;
	if (!fopen_s(&scr, source, "r")) {
		long handle = _fileno(scr);
		char* data = new char[size];
		if (!fopen_s(&dst, destination, "wb")) {
			int realsize;
			while (!feof(scr)) {
				realsize = fread(data, sizeof(char), size, scr);
				fwrite(data, sizeof(char), realsize, dst);
			}
		}
		else {
			delete[] data;
			cout << "Ошибка при работе с файлом!\n";
			flag = false;
		}
		fclose(scr);
		fclose(dst);
	}
	else {
		cout << "Ошибка при работе с файлом!\n";
		flag = false;
	}
	if (!flag) {
		Sleep(1500);
		return;
	}
	cout << "Файл успешно скопирован!\n";
	Sleep(1500);
}



void RemoveFile() {
	system("cls");
	char* name = new char[_MAX_PATH];

	cout << "Введите имя файла: "; cin >> name;
	//%
	if (_access(name, 00) == -1) {
		cout << "\tУказан неверный путь к файлу или его название\n";
		Sleep(1500);
		return;
	}

	if (remove(name) != 0)
		cout << "Ошибка!\n Файл не был удалён\n";
	else
		cout << "Файл успешно удалён!\n";
}



void SizeFile() {
	system("cls");
	char* path = new char[_MAX_PATH];

	cout << "Введите путь к файлу: "; cin >> path;
	//%

	if (_access(path, 00) == -1) {
		cout << "\tУказан неверный путь к файлу или его название\n";
		Sleep(1500);
		return;
	}

	_finddata_t* fileinfo = new _finddata_t;
	intptr_t done = _findfirst(path, fileinfo);

	cout << "Размер файла по указанному пути:\n" << fileinfo->size << " байт" << endl;

	cout << "\nНажмите любую клавишу для продолжения ...\n";
	_getch();
}



void SearchFiles() {
	system("cls");
	char* path = new char[_MAX_PATH - 15];
	char* mask = new char[15];
	cout << "Введите путь: "; cin >> path;
	cout << "Введите маску: "; cin >> mask;

	strcat_s(path, _MAX_PATH+2,mask);



	_finddata_t* fileinfo = new _finddata_t;
	intptr_t done = _findfirst(path, fileinfo);

	cout << "Все названия файлов удовлетворяющих условию\n";
	do {
		cout << fileinfo->name << endl;
	} while (_findnext(done, fileinfo) != -1);

	_findclose(done);

	delete fileinfo;

	cout << "\nНажмите любую клавишу для продолжения ...\n";
	_getch();
}



int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int key = 1;

	while (key != 0) {
		system("cls");

		key = DisplayMenu();

		switch (key) {
		case 49:
		case 50:
		case 51:
			RemoveFile();
			break;
		case 52:
			RenameFile();
			break;
		case 53:
			CopyFile_();
			break;
		case 54:
			SizeFile();
			break;
		case 55:
			SearchFiles();
			break;
		case 56:
		case 57:
		case 58:
			break;
		}
	}
}

