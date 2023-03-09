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
	if (!filesystem::exists(name))
		return -1;
	return filesystem::remove_all(name);
}

int Directory::size() {
	if (!filesystem::exists(name))
		return -1;
	return filesystem::file_size(name);
}

int Directory::create() {
	if (!filesystem::exists(name))
		return -1;
	return filesystem::create_directory(name);
}

int Directory::copy(char* name_from,const char mode[3]) {
	if (!filesystem::exists(name) || !filesystem::exists(name_from))
		return -1;

	if (!strcmp(mode, "all")) {
		if (strstr(name_from, name))
			return -1;
		filesystem::copy(name_from, name, filesystem::copy_options::recursive | 
			filesystem::copy_options::overwrite_existing);
	}

	else if (strcmp(mode, "fls")) {
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

void Directory::showDisks() {

}