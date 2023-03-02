#include <iostream>
#include <Windows.h>

using namespace std;


string RussianMessage(const char* str) {
	char message[100];
	CharToOemA(str, message);
	return message;
}


// Base class of exception classes
class BaseException {
protected:
	string explanation;
public:
	virtual string show() = 0;
};



