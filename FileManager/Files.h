#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>;
#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <filesystem>
#include <fileapi.h>


using namespace std;

class FilesName {
protected:
	char* name;
	int size;
	FilesName(char* n) {
		size = strlen(n) + 2;
		name = new char[size];
		strcpy_s(name, size, n);
	}
	~FilesName() {
		delete[] name;
	}
};



class InFiles : public FilesName {
public:
	InFiles(char* n) : FilesName(n) {};

	virtual int show_data();
	virtual int redact(char* );
	virtual int clear();
};


class Files : public FilesName
{
public:
	Files(char* n) : FilesName(n) {};

	int rename_(char* ); // Rename file
	bool create(); // Create file
	int delete_(); // Delete file
	int copy(char*); // Copy file
	int size(); // Know size of file
	static int search_on_name(const char*, char*); // Search file on name
};

