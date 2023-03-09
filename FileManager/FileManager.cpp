

#include <iostream>
#include <cstdlib>
#include <conio.h>;
#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <filesystem>
#include <fileapi.h>

#include "Files.h"
#include "Menu.h"
#include "Directory.h"

using namespace std;

// Текстовые файлы
void ShowDataFiles() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;
	

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не сущесвует\n";
		Sleep(2000);
		return;
	}

	InFiles* file = new InFiles(name);

	cout << "Содержимое файла:\n";
	if (!file->show_data())
		cout << "Ошибка при открытии файла!\n";

	delete file;

	Sleep(2000);
}
void EditFile(int mode = 0) {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не сущесвует\n";
		Sleep(2000);
		return;
	}

	cout << "Введите новый текст в файл:\n";
	char* text = new char[25000];

	cin.ignore();
	gets_s(text, 25001);

	InFiles* file = new InFiles(name);

	if (mode != 0)
		file->clear();

	if (file->redact(text))
		cout << "Успешная запись в файл!\n";
	else
		cout << "Ошибка при записи или открытия файла\n";

	delete file;

	Sleep(2000);
}
void ClearFile() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не сущесвует\n";
		Sleep(2000);
		return;
	}

	InFiles* file = new InFiles(name);

	if (file->clear())
		cout << "Файл успешно был очищен!\n";
	else
		cout << "Ошибка при открытии файла\n";

	delete file;

	Sleep(2000);
}

//Директории
void CreateDirectory_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;

	if (filesystem::exists(name)) {
		cout << "\nТакая директория уже существует\n";
		Sleep(2000);
		return;
	}

	if (!filesystem::is_directory(name)) {
		cout << "Введённо имя не является диркеторией\n";
		Sleep(2000);
		return;
	}

	Directory* dir = new Directory(name);

	if (dir->create() == false)
		cout << "\nОшибка при создании директории\n";
	else
		cout << "\nДиректория успешно создана!\n";

	delete dir;

	Sleep(2000);
}
void DeleteDirectory_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;

	if (!filesystem::exists(name)) {
		cout << "\nТакой директории не существует\n";
		Sleep(2000);
		return;
	}

	if (!filesystem::is_directory(name)) {
		cout << "Введённо имя не является диркеторией\n";
		Sleep(2000);
		return;
	}

	Directory* dir = new Directory(name);

	if (dir->delete_() == false)
		cout << "\nОшибка при удалении директории\n";
	else
		cout << "\nДиректория успешно удалена!\n";

	delete dir;

	Sleep(2000);
}
void SizeOfDirectory() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;

	if (!filesystem::exists(name)) {
		cout << "\nТакой директории не существует\n";
		Sleep(2000);
		return;
	}
	if (!filesystem::is_directory(name)) {
		cout << "Введённо имя не является диреторией\n";
		Sleep(2000);
		return;
	}

	Directory* dir = new Directory(name);


	cout << "Размер директории - " << dir->size() << " байт" << endl;

	delete dir;

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}
void CopyDirectory() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя копируемой директории:\n";
	cin >> name;

	if (!filesystem::exists(name)) {
		cout << "\nТакой директории не существует\n";
		Sleep(2000);
		return;
	}
	if (!filesystem::is_directory(name)) {
		cout << "\nВведённо имя не является диреторией\n";
		Sleep(2000);
		return;
	}

	char* path = new char[_MAX_PATH];
	cout << "Введите путь новой директории:\n";
	cin >> path;

	char mode[3];
	cout << "Введите тип копирования (all - с подкаталогами, fls - только файлы и файлы из подкаталогов):\n";
	cin >> mode;

	Directory* dir = new Directory(path);

	if (dir->copy(name,mode))
		cout << "\nДиректория успешно скопирована!\n";
	else
		cout << "\nОшибка при работе с директориями\n";

	delete dir;
	Sleep(2000);
}
// Файлы
void RenameFileDir() {
	system("cls");

	char* oldName = new char[_MAX_PATH];
	char* newName = new char[_MAX_PATH];

	cout << "Введите старое имя файла:\n";
	cin >> oldName;
	if (_access(oldName,00) == -1) {
		cout << "\nОшибка! Указанный файл не найден или недоступен\n";
		return;
	}

	cout << "Введите новое имя файла:\n";
	cin >> newName;

	Files* file = new Files(oldName);

	if (file->rename_(newName) == 0)
		cout << "\nФайл/папка был успешно переименова!\n";
	else 
		cout << "\nОшибка при переименовании файла/папки!\n";


	delete file;

	Sleep(2000);
}
void CreateFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	if (_access(name, 00) == 0) {
		cout << "\nТакой файл уже существует\n";
		Sleep(2000);
		return;
	}

	Files *file = new Files(name);

	if (file->create() == true) 
		cout << "\nОшибка при создании файла\n";
	else
		cout << "\nФайл успешно создан!\n";

	delete file;

	Sleep(2000);
}
void DeleteFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не сущесвует\n";
		Sleep(2000);
		return;
	}
	Files* file = new Files(name);

	if (file->delete_() == 0)
		cout << "\nФайл успешно удалён!\n";
	else
		cout << "\nОшибка при удалении файла!\n";

	Sleep(2000);
}
void SizeOfFile() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не сущесвует\n";
		Sleep(2000);
		return;
	}
	
	Files* file = new Files(name);

	int size = file->size();

	if(size != -1)
		cout << "Размер данного файла - " << size << " байт\n";
	else
		cout << "\nОшибка при открытии файла\n";

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}
void SearchInDirectory() {
	system("cls");
	char* path = new char[_MAX_PATH - 15];
	char* mask = new char[15];
	
	cout << "Введите путь:\n";
	cin >> path;
	cout << "Введите маску:\n";
	cin >> mask;

	cout << "\n\n Найденные файлы по запросу:\n";

	vector<string> files;
	Files* file = new Files(path);

	file->search(path,files,mask);

	for (vector<string>::iterator iter = files.begin(); iter != files.end(); iter++) {
		cout << *iter << endl;
	}

	delete file;

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}
void ShowDisks() {
	/*vector<string> files;

	cout << "Диск C:\n";
	Files::showDisks("C:\\Test",files);

	for (vector<string>::iterator iter = files.begin(); iter != files.end(); iter++) {
		cout << *iter << endl;
	}

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();*/
}
void CopyFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя копируемого файла:\n";
	cin >> name;

	if (_access(name, 00) == -1) {
		cout << "\nТакого файла не существует\n";
		Sleep(2000);
		return;
	}

	char* path = new char[_MAX_PATH];
	cout << "\nВведите путь копии файла\n";
	cin >> path;

	Files* file = new Files(path);

	if (file->copy(name)) 
		cout << "\nФайл успешно скопирован!\n";
	else
		cout << "\nОшибка при работе с файлами\n";

	delete file;
	Sleep(2000);
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int key = 0;
	Menu menu, menu2, menu3;

	 
	while (key != 1) {
		system("cls");

		switch (key = menu.DisplayMenu()) {
		case 1: 
			ShowDisks();
			break;
		case 2: 
			system("cls");
			switch (menu3.DisplayMenuFileDir()) {
			case 1:
				CreateFile_();
				break;
			case 2:
				CreateDirectory_();
				break;
			}
			break;
		case 3: 
			system("cls");
			switch (menu3.DisplayMenuFileDir()) {
			case 1:
				DeleteFile_();
				break;
			case 2:
				DeleteDirectory_();
				break;
			}
			break;
		case 4: 
			RenameFileDir();
			break;
		case 5:
			system("cls");
			switch (menu3.DisplayMenuFileDir()) {
			case 1:
				CopyFile_();
				break;
			case 2:
				CopyDirectory();
				break;
			}
			break;
		case 6: 
			system("cls");
			switch (menu3.DisplayMenuFileDir()) {
			case 1:
				SizeOfFile();
				break;
			case 2:
				SizeOfDirectory();
				break;
			}
			break;
		case 7: 
			SearchInDirectory();
			break;
		case 8: 
			break;
		case 10:
			ShowDataFiles();
			break;
		case 9:
			system("cls");
			
			switch (menu2.DisplayMenuEditFile()) {
			case 1:
				ClearFile();
				break;
			case 2:
				EditFile();
				break;
			case 3:
				EditFile(1);
			}
			break;
		}
	}
}

