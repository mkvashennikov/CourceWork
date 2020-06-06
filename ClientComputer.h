#pragma once
#include "Computer.h"
/*
* Класс клиентский компьютер. Унаследован от класса компьютер.
*/
class ClientComputer : public Computer {
public:
    ClientComputer();
    ClientComputer(const ClientComputer& comp);
    void PrintAllInformation() override;
    void SetUsername(char* username);
    char* GetUsername() const;
    ClientComputer& operator=(const ClientComputer& comp);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~ClientComputer();
protected:
    char* Username;
};