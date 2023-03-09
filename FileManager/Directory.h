#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>;
#include <Windows.h>
#include <string>

using namespace std;

class Directory
{
	char* name;
public:
	Directory(char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 2, n);
	}
	int create();
	int delete_();
	int size();
	int copy(char* , const char[]);
	static void showDisks();
};

