#pragma once
#include "INetwork.h"
/*
* Класс Сетевое устройство. Унаследован от класса-интерфейса.
Класс предназначен для работы с сетевыми устройствами.
*/

class NetworkDevice : public INetwork {
public:
    NetworkDevice();
    NetworkDevice(const NetworkDevice& nd);
    void PrintAllInformation() override;
    double GetPrice()const override;
    char* GetName()const override;
    char* GetManufacturer()const override;
    void SetPrice(double price) override;
    void SetName(char* name) override;
    void SetManufacturer(char* manufacturer) override;
    void SetConnectedDeviceCount(int c);
    int GetConnectedDeviceCount() const;
    NetworkDevice& operator=(const NetworkDevice& nd);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~NetworkDevice();
protected:
    char* Name;
    char* Manufacturer;
    int ConnectedDeviceCount;
    double Price;
};
