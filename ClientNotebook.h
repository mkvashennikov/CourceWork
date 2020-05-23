#pragma once
#include "ClientComputer.h"
/*
* Класс клиентский ноутбук. Унаследован от класса "Клиентский компьютер".
*/

class ClientNotebook : public ClientComputer {
public:
    ClientNotebook();
    ClientNotebook(const ClientNotebook& comp);
    void PrintAllInformation() override;
    void ChangeWebCamStatus();
    void SetWebCamStatus(bool status);
    void SetBatteryCapacity(double capacity);
    bool GetWebCamStatus() const;
    double GetBatteryCapacity() const;
    ClientNotebook& operator=(const ClientNotebook& cn);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
private:
    bool WebCamStatus;
    double BatteryCapacity;
};