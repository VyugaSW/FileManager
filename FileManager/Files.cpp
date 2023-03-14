#include "Files.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fstream>
#include <iomanip>
#include <filesystem>

// Show data from text file
int InFiles::show_data() {
	if (_access(name, 00) == -1) // If file doesn't exist
		return -1;

	char* temp = new char[65235];
	fstream f(name,ios::in);

	if (!f) // If file wasn't opened
		return -1;

	while (!f.eof()) {
		f.getline(temp, 65236);
		cout << temp << endl;
	};

	return 1;
}

// Redact text file
int InFiles::redact(char* text){
	if (_access(name, 00) == -1) // If file doesn't exist
		return -1;

	fstream f(name, ios::out | ios::app);

	if (!f) // If file wasn't opened
		return -1;
	f << text;
	f.close();

	return 1;
}

// Clear text file
int InFiles::clear() {
	if (_access(name, 00) == -1) // If file doesn't exist
		return -1;
	ofstream clear_f(name); 
	if (!clear_f) // If file wasn't opened
		return -1;

	clear_f.close();

	return 1;
}




// Rename file
int Files::rename_(char* newName) {
	if (_access(name, 00) == -1) // If file (for copy) doesn't exist
		return -1;
	return rename(name, newName);
}

// Create file
bool Files::create() {
	if (_access(name, 00) == 0) // If file with this path already exists
		return false;
	ofstream f(name);
	if (!f.is_open()) // If file wasn't opened
		return false;
	if (!f)
		return false;
	f.close();
	return f.bad();
}

// Delete file
int Files::delete_() {
	if (_access(name, 00) == -1) // If file doesn't exist
		return -1;
	return remove(name);
}

// Know size of file
int Files::size() {
	if (_access(name, 00) == -1) // If file doesn't exist
		return -1;
	return filesystem::file_size(name);
}


// Search file on name
int Files::search_on_name(const char* path, char* name) {
	if (!filesystem::exists(path)) // If this path doesn't exist
		return -1;
	for (auto const& dir : filesystem::directory_iterator(path)) {
		try {
			// File with name "$RECYCLE.BIN" is trash from basket, and it
			// generates exceptional errors, so this skips thanks to "try" and "catch"
			if (strstr(dir.path().string().c_str(), ":\\$RECYCLE.BIN")) {
				throw NULL;
			}
			// If path is directory
			if (dir.is_directory()) {
				search_on_name(dir.path().string().c_str(),name);
			}
			// If path is searching name
			if (!strcmp((dir.path().filename().string()+dir.path().extension().string()).c_str(), name)) {
				cout << dir.path().string();
				break;
			}
		}
		catch (...) {
			continue;
		}
	}
	return 1;
}

// Copy file
int Files::copy(char* name_from) {
	if (!strcmp(name_from, name)) // If name from copy and name to copy is same
		return -1;
	if (_access(name_from,00) == -1) // If name (from copy) doesn't exist
		return -1;
	if (_access(name, 00) == -1) // If name to copy doesn't exist
		return -1;

	filesystem::copy(name_from, name,filesystem::copy_options::overwrite_existing);
	return 1;
}
