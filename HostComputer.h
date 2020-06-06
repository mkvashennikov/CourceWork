#pragma once
#include "Computer.h"
/*
* Хост-компьютер. Является наследником класса Computer.
Предназначен для описания компьютеров-хостов.
*/
class HostComputer : public Computer {
public:
    HostComputer();
    HostComputer(const HostComputer& comp);
    void PrintAllInformation() override;
    void SetConnectCount(int count);
    void SetIP(char* ip);
    void SetProtocol(char* protocol);
    int GetConnectCount() const;
    char* GetIP() const;
    char* GetProtocol() const;
    HostComputer& operator=(const HostComputer& comp);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~HostComputer();
private:
    char* IP;
    char* Protocol;
    int ConnectedCount;
};
