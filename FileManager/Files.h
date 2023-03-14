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

class InFiles
{
protected:
	char* name;
public:
	InFiles(char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 2, n);
	}

	int show_data();
	int redact(char* );
	int clear();
};


class Files : public InFiles
{
public:
	Files(char* n) : InFiles(n) {};

	int rename_(char* ); // Rename file
	bool create(); // Create file
	int delete_(); // Delete file
	int copy(char*); // Copy file
	int size(); // Know size of file
	static int search_on_name(const char* ); // Search file on name
};

