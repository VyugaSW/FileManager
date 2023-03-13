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
	int create(); // Create directory
	int delete_(); // Delete directory
	int size(); // Know size of directory
	int copy(char* , char[]); // Copy directory
	static void showDisk(const char*); // Show all files of disk
	static void search(char*, vector<string>&, char*); // Search files in directory
};

