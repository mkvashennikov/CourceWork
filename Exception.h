#pragma once
/*
*�����-����������. ������ ��������������� ��������� ��� ���������
�������������� ��������.
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
