#pragma once
#include "ClientComputer.h"
/*
* Класс Клиентский персональный компьютер. Унаследован от класса "Клиентский компьютер".
*/

class ClientPC : public ClientComputer {
public:
    ClientPC();
    ClientPC(const ClientPC& comp);
    void PrintAllInformation() override;
    void SetLicencedOS(bool licenced);
    bool GetLicencedOS() const;
    ClientPC& operator=(const ClientPC& comp);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
private:
    bool LicencedOS;
};
