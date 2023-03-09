#include "Files.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fstream>
#include <iomanip>
#include <filesystem>


int InFiles::show_data() {
	if (_access(name, 00) == -1)
		return -1;

	char* temp = new char[65235];
	fstream f(name,ios::in);

	if (!f)
		return -1;

	while (!f.eof()) {
		//f.get(temp);
		cout << temp << endl;
	};

	return 1;
}

int InFiles::redact(char* text){
	if (_access(name, 00) == -1)
		return -1;

	fstream f(name, ios::out | ios::app);

	if (!f)
		return -1;
	f << text;
	f.close();

	return 1;
}

int InFiles::clear() {
	if (_access(name, 00) == -1)
		return -1;
	ofstream clear_f(name);
	if (!clear_f)
		return -1;

	clear_f.close();

	return 1;
}





int Files::rename_(char* newName) {
	if (_access(name, 00) == -1)
		return -1;
	return rename(name, newName);
}

bool Files::create() {
	ofstream f(name);
	f.close();
	if (!f)
		return false;

	return f.bad();
}

int Files::delete_() {
	if (_access(name, 00) == -1)
		return -1;
	return remove(name);
}

int Files::size() {
	if (_access(name, 00) == -1)
		return -1;
	return filesystem::file_size(name);
}

void Files::search(char* name, vector<string>& files, char* mask) {
	if (!filesystem::exists(name))
		return;
	for (const auto& f : filesystem::directory_iterator(name)) {
		if (filesystem::is_directory(f)) {
			search((char*)f.path().string().c_str(), files, mask);
		}
		else {
			if (f.path().extension().string() == mask || !strcmp(mask,".")) {
				files.push_back(f.path().filename().string());
			}
		}
	}
}

int Files::search_on_name() {
	return 0;
}

int Files::copy(char* name_from) {
	if (!strcmp(name_from, name))
		return -1;

	filesystem::copy(name_from, name,filesystem::copy_options::overwrite_existing);
	return 1;
}
