#pragma once
#include "NetworkDevice.h"
/*
* Класс сетевой принтер. Унаследован от класса "Сетевое устройство".
*/

class NetworkPrinter : public NetworkDevice {
public:
    NetworkPrinter();
    NetworkPrinter(const NetworkPrinter& np);
    void PrintAllInformation() override;
    void SetColorType(bool type);
    void SetType(char* type);
    void SetMaxResolution(char* resolution);
    void SetMaxPaperSize(char* papersize);
    void SetWindowsSupport(char* WindowsSupport);
    void SetColor(char* color);
    void SetPrintSpeed(int printspeed);
    void SetWiFiSupport(bool spt);
    void SetBlueToothModule(bool blm);
    void SetPaperCapacity(int cpt);
    bool GetColorType() const;
    char* GetType() const;
    char* GetMaxResolution() const;
    char* GetMaxPaperSize() const;
    char* GetWindowsSupport() const;
    char* GetColor() const;
    int GetPrintSpeed() const;
    bool GetWiFiSupport() const;
    bool GetBluetoothModule() const;
    int GetPaperCapacity() const;
    NetworkPrinter& operator=(const NetworkPrinter& np);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~NetworkPrinter();
private:
    bool ColoredType;
    char* Type;
    char* MaxResolution;
    char* MaxPaperSize;
    char* WindowsSupport;
    char* Color;
    int PrintSpeed;
    bool WiFiSupport;
    bool BluetoothModule;
    int PaperCapacity;
};