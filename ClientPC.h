#pragma once
#include "ClientComputer.h"
/*
* ����� ���������� ������������ ���������. ����������� �� ������ "���������� ���������".
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
