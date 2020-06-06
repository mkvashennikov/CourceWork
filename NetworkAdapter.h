#pragma once
#include "NetworkDevice.h"
/*
* Класс Сетевой адаптер. Унаследован от класса "Сетевое устройство".
*/

class NetworkAdapter : public NetworkDevice {
public:
    NetworkAdapter();
    NetworkAdapter(const NetworkAdapter& na);
    void PrintAllInformation() override;
    void SetType(char* type);
    void SetWiFiProtocol(char* protocol);
    void SetIntefaceConnect(char* interface);
    void SetMACAdress(char* mac);
    void SetSpeed(double speed);
    void SetCountAntennas(int count);
    void ChangeNetworkMedia(bool nm);
    char* GetType() const;
    char* GetWiFiProtocol() const;
    char* GetIntefaceConnect() const;
    char* GetMACAdress() const;
    double GetSpeed() const;
    int GetCountAntennas() const;
    bool GetNetworkMedia() const;
    NetworkAdapter& operator=(const NetworkAdapter& na);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~NetworkAdapter();
private:
    char* Type;
    char* WiFiProtocol;
    char* InterfaceConnect;
    char* MACAdress;
    double Speed;
    int CountAntennas;
    bool NetworkMedia;
};