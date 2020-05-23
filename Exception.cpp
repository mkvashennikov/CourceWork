#include "Exception.h"
#include <iostream>

Exception::Exception() {
	Msg = new char[40];
	strcpy(Msg,"Произошло исключение неопознанного типа");
}
Exception::Exception(const char* msg) {
	Msg = new char[strlen(msg)+1];
	strcpy(Msg,msg);
}
const char* Exception::GetError() const {
	return Msg;
}
Exception::~Exception() {
	delete[] Msg;
}