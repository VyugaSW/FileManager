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

	int rename_(char* );
	bool create();
	int delete_();
	int copy(char*);
	int size();
	void search(char*, vector<string>&, char*);
	int search_on_name();
};

