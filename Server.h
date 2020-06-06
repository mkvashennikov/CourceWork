#pragma once
#include "Computer.h"
/*
* Класс Сервер. Унаследован от класса компьютер.
*/

class Server : public Computer {
public:
    Server();
    Server(const Server& serv);
    void PrintAllInformation() override;
    void SetAdmin(char* admin);
    char* GetAdmin() const;
    Server& operator=(const Server& serv);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~Server();
private:
    char* Admin;
};
