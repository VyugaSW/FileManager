#include "Directory.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <fileapi.h>

using namespace std;

int Directory::delete_() {
	if (!filesystem::exists(name)) // If this directory doesn't exist
		return -1;
	return filesystem::remove_all(name);
}

int Directory::size() {
	if (!filesystem::exists(name)) // If this directory doesn't exist
		return -1;
	return filesystem::file_size(name);
}

int Directory::create() {
	if (filesystem::exists(name)) // If this directory exists
		return -1;
	return filesystem::create_directory(name);
}

int Directory::copy(char* name_from, char mode[3]) {
	if (!filesystem::exists(name) || !filesystem::exists(name_from)) // If this directory/directory for copy doesn't exist
		return -1;

	if (!strcmp(mode, "all")) { // If mode = all
		if (strstr(name_from, name)) // If copy path is new path
			return -1;
		// Copy directory with subdirectories;
		filesystem::copy(name_from, name, filesystem::copy_options::recursive | 
			filesystem::copy_options::overwrite_existing);
	}

	else if (strcmp(mode, "fls")) { // If mode = fls
		// Copy only files from directories and subdirectories use a recursion
		filesystem::copy(name_from, name, filesystem::copy_options::overwrite_existing);
		for (const auto& f : filesystem::directory_iterator(name_from)) {
			if (filesystem::is_directory(f) && strcmp(name, f.path().string().c_str()) != 0) {
				copy((char*)f.path().string().c_str(),mode);
			}
		}
	}
	else return -1;

	return 1;
}

void Directory::showDisk(const char* path) {
	if(!filesystem::exists(path)) // If this disk doesn't exist
		return;
	for (auto const& dir : filesystem::directory_iterator(path)) {
		try {
			// File with name "$RECYCLE.BIN" is trash from basket, and it
			// generates exceptional errors, so this skips thanks to "try" and "catch"
			if (strstr(dir.path().string().c_str(), ":\\$RECYCLE.BIN")) {
				throw NULL;
			}
			// If path is directory
			if (dir.is_directory()) {
				showDisk(dir.path().string().c_str());
			}
			// If path is file
			else {
				cout << dir.path().string() << endl;
			}
		}
		catch (...) {
			continue;
		}
	}
}

// Search files in directory
void Directory::search(char* name, vector<string>& files, char* mask) {
	if (!filesystem::exists(name)) // If directory doesn't exist
		return;
	for (const auto& f : filesystem::directory_iterator(name)) {
		if (filesystem::is_directory(f)) { // If current path is directory
			search((char*)f.path().string().c_str(), files, mask);
		}
		else { // If current path not is directory
			if (f.path().extension().string() == mask || !strcmp(mask, ".")) {
				files.push_back(f.path().filename().string());
			}
		}
	}
}