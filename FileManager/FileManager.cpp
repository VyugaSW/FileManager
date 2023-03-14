

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


// Text files

// Show data from file
void ShowDataFiles() {
	system("cls");
	// Enter path to file
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	InFiles file(name);

	cout << "Содержимое файла:\n";
	// Check
	if (!file.show_data())
		cout << "Ошибка при открытии файла!\n";


	Sleep(2000);
}
// Redact file
void EditFile(int mode = 0) {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	cout << "Введите новый текст в файл:\n";
	char* text = new char[25000];

	// Clear flow
	cin.ignore();
	gets_s(text, 25001);

	InFiles file(name);

	if (mode != 0)
		file.clear();

	if (file.redact(text))
		cout << "Успешная запись в файл!\n";
	else
		cout << "Ошибка при записи или открытия файла\n";


	Sleep(2000);
}
// Clear file from text
void ClearFile() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	InFiles file(name);

	if (file.clear())
		cout << "Файл успешно был очищен!\n";
	else
		cout << "Ошибка при открытии файла\n";


	Sleep(2000);
}


// Directories

// Create new directory
void CreateDirectory_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;

	Directory dir(name);

	if (dir.create() == false)
		cout << "\nОшибка при создании директории\n";
	else
		cout << "\nДиректория успешно создана!\n";

	Sleep(2000);
}
// Delete directory
void DeleteDirectory_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;


	Directory dir(name);

	if (dir.delete_() == false)
		cout << "\nОшибка при удалении директории\n";
	else
		cout << "\nДиректория успешно удалена!\n";


	Sleep(2000);
}
// Know size of directory
void SizeOfDirectory() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя директории:\n";
	cin >> name;


	Directory dir(name);


	cout << "Размер директории - " << dir.size() << " байт" << endl;


	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}
// Copy directory
void CopyDirectory() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя копируемой директории:\n";
	cin >> name;

	char* path = new char[_MAX_PATH];
	cout << "Введите путь новой директории:\n";
	cin >> path;

	char mode[3];
	// all - copy directory with subdirectories, fls - copy only files from directory and subdirectories
	cout << "Введите тип копирования (all - с подкаталогами, fls - только файлы и файлы из подкаталогов):\n";
	cin >> mode;

	Directory dir(path);

	if (dir.copy(name,mode))
		cout << "\nДиректория успешно скопирована!\n";
	else
		cout << "\nОшибка при работе с директориями\n";

	Sleep(2000);
}
// Search files in direcory (with mask or without mask)
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

	Directory::search(path, files, mask);

	for (vector<string>::iterator iter = files.begin(); iter != files.end(); iter++) {
		cout << *iter << endl;
	}

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}


// Disk

// Show all files of disk
void ShowDisk() {
	system("cls");
	char* name = new char[25];
	cout << "Введите имя диска (C:\\ / D:\\):\n";
	cin >> name;
	cout << "НАЙДЕННЫЕ ФАЙЛЫ:\n";
	Directory::showDisk(name);
}


// Files

// Rename file of directory
void RenameFileDir() {
	system("cls");

	char* oldName = new char[_MAX_PATH];
	char* newName = new char[_MAX_PATH];

	cout << "Введите старое имя файла:\n";
	cin >> oldName;

	cout << "Введите новое имя файла:\n";
	cin >> newName;

	Files file(oldName);

	if (file.rename_(newName) == 0)
		cout << "\nФайл/папка был успешно переименова!\n";
	else 
		cout << "\nОшибка при переименовании файла/папки!\n";



	Sleep(2000);
}
// Create new file
void CreateFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	Files file(name);

	if (file.create() == true) 
		cout << "\nОшибка при создании файла\n";
	else
		cout << "\nФайл успешно создан!\n";

	Sleep(2000);
}
// Delete file
void DeleteFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	Files file(name);

	if (file.delete_() == 0)
		cout << "\nФайл успешно удалён!\n";
	else
		cout << "\nОшибка при удалении файла!\n";

	Sleep(2000);
}
// Know size of file
void SizeOfFile() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя файла:\n";
	cin >> name;

	
	Files file(name);

	int size = file.size();

	if(size != -1)
		cout << "Размер данного файла - " << size << " байт\n";
	else
		cout << "\nОшибка при открытии файла\n";

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}
// Cope file
void CopyFile_() {
	system("cls");
	char* name = new char[_MAX_PATH];
	cout << "Введите имя копируемого файла:\n";
	cin >> name;

	char* path = new char[_MAX_PATH];
	cout << "\nВведите путь копии файла\n";
	cin >> path;

	Files file(name);

	if (file.copy(name)) 
		cout << "\nФайл успешно скопирован!\n";
	else
		cout << "\nОшибка при работе с файлами\n";

	Sleep(2000);
}
// Search file on name
void SearchOnName() {
	system("cls");
	char* name = new char[_MAX_PATH];
	char* path = new char[_MAX_PATH];
	cout << "Введите имя искомого файла (только название и расширение):\n";
	cin >> name;
	cout << "Введите самое приближенную область поиска:\n";
	cin >> path;

	if (!Files::search_on_name(path,name)) 
		cout << "\nОшибка при поиске!\n";

	cout << "Полный путь к файлу:\n";

	cout << "\nНажмите любую клавишу для продолжения ... \n";
	_getch();
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Menu menu, menu2, menu3;
	// Main loop
	while (true) {
		system("cls");

		switch (menu.DisplayMenu()) {
			// Show disk
		case 1: 
			ShowDisk();
			break;
			// Create file or directory
		case 2: 
			system("cls");
			// Menu for directory or file
			switch (menu3.DisplayMenuFileDir()) {
			case 1:
				CreateFile_();
				break;
			case 2:
				CreateDirectory_();
				break;
			}
			break;
			// Delete file or directory
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
			// Rename file or directory
		case 4: 
			RenameFileDir();
			break;
			// Copy file or directory
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
			// Size of file or directory
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
			// All files (with mask) in directory
		case 7: 
			SearchInDirectory();
			break;
			// Search on name of file()
		case 8:
			SearchOnName();
			break;
			// Show data in file
		case 10:
			ShowDataFiles();
			break;
			// Interact with text files
		case 9:
			system("cls");
			switch (menu2.DisplayMenuEditFile()) {
			case 1:
				// Clear file
				ClearFile();
				break;
			case 2:
				// Redact file
				EditFile();
				break;
			case 3:
				// Clear and redact file
				EditFile(1);
			}
			break;
		}
	}
}

