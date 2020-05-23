#pragma once
/*
*Класс-исключений. Служит вспомогательным элементом для обработки
исключительных ситуаций.
*/
class Exception {
public:
	Exception();
	Exception(const char* msg);
	const char* GetError() const;
	~Exception();
private:
	char* Msg;
};
