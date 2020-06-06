#include "NetworkPrinter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

NetworkPrinter::NetworkPrinter() {
    Name = new char[8];
    strcpy(Name, "Printer");
    Manufacturer = new char[6];
    strcpy(Manufacturer, "Empty");
    Type = new char[6];
    strcpy(Type, "Empty");
    MaxResolution = new char[10];
    strcpy(MaxResolution, "1920x1080");
    MaxPaperSize = new char[3];
    strcpy(MaxPaperSize, "A4");
    WindowsSupport = new char[22];
    strcpy(WindowsSupport, "Windows 7, Windows 10");
    Color = new char[6];
    strcpy(Color, "Black");
    ColoredType = false;
    PrintSpeed = 5;
    WiFiSupport = false;
    BluetoothModule = false;
    PaperCapacity = 10;
}
NetworkPrinter::NetworkPrinter(const NetworkPrinter& np) {
    Name = new char[strlen(np.Name) + 1];
    strcpy(Name, np.Name);
    Manufacturer = new char[strlen(np.Manufacturer) + 1];
    strcpy(Manufacturer, np.Manufacturer);
    Type = new char[strlen(np.Type) + 1];
    strcpy(Type, np.Type);
    MaxResolution = new char[strlen(np.MaxResolution) + 1];
    strcpy(MaxResolution, np.MaxResolution);
    MaxPaperSize = new char[strlen(np.MaxPaperSize) + 1];
    strcpy(MaxPaperSize, np.MaxPaperSize);
    WindowsSupport = new char[strlen(np.WindowsSupport) + 1];
    strcpy(WindowsSupport, np.WindowsSupport);
    Color = new char[strlen(np.Color) + 1];
    strcpy(Color, np.Color);
    ConnectedDeviceCount = np.ConnectedDeviceCount;
    Price = np.Price;
    ColoredType = np.ColoredType;
    PrintSpeed = np.PrintSpeed;
    WiFiSupport = np.WiFiSupport;
    BluetoothModule = np.BluetoothModule;
    PaperCapacity = np.PaperCapacity;
}
void NetworkPrinter::PrintAllInformation() {
    cout << "Название устройства: " << Name << endl;
    cout << "Производитель устройства: " << Manufacturer << endl;
    cout << "Количество подключенных устройств: " << ConnectedDeviceCount << endl;
    cout << "Стоимость: " << Price << endl;
    cout << "Цветной: " << ColoredType << endl;
    cout << "Максимальное разрешение: " << MaxResolution << endl;
    cout << "Максимальный размер листа: " << MaxPaperSize << endl;
    cout << "Поддержка Windows: " << WindowsSupport << endl;
    cout << "Цвет принтера: " << Color << endl;
    cout << "Скорость печати: " << PrintSpeed << endl;
    cout << "Поддержка Wi-Fi: " << WiFiSupport << endl;
    cout << "Наличие Bluetooth модуля: " << BluetoothModule << endl;
    cout << "Вместимость листов: " << PaperCapacity << endl;
}
void NetworkPrinter::SetColorType(bool ct) {
    ColoredType = ct;
}
void NetworkPrinter::SetType(char* type) {
    delete[] Type;
    Type = new char[strlen(type) + 1];
    strcpy(Type, type);
}
void NetworkPrinter::SetMaxResolution(char* rs) {
    delete[] MaxResolution;
    MaxResolution = new char[strlen(rs) + 1];
    strcpy(MaxResolution, rs);
}
void NetworkPrinter::SetMaxPaperSize(char* ps) {
    delete[] MaxPaperSize;
    MaxPaperSize = new char[strlen(ps) + 1];
    strcpy(MaxPaperSize, ps);
}
void NetworkPrinter::SetWindowsSupport(char* ws) {
    delete[] WindowsSupport;
    WindowsSupport = new char[strlen(ws) + 1];
    strcpy(WindowsSupport, ws);
}
void NetworkPrinter::SetColor(char* cl) {
    delete[] Color;
    Color = new char[strlen(cl) + 1];
    strcpy(Color, cl);
}
void NetworkPrinter::SetPrintSpeed(int ps) {
    PrintSpeed = ps;
}
void NetworkPrinter::SetWiFiSupport(bool ws) {
    WiFiSupport = ws;
}
void NetworkPrinter::SetBlueToothModule(bool bm) {
    BluetoothModule = bm;
}
void NetworkPrinter::SetPaperCapacity(int cp) {
    PaperCapacity = cp;
}
char* NetworkPrinter::GetType() const {
    return Type;
}
bool NetworkPrinter::GetColorType() const {
    return ColoredType;
}
char* NetworkPrinter::GetMaxResolution() const {
    return MaxResolution;
}
char* NetworkPrinter::GetMaxPaperSize() const {
    return MaxPaperSize;
}
char* NetworkPrinter::GetWindowsSupport() const {
    return WindowsSupport;
}
char* NetworkPrinter::GetColor() const {
    return Color;
}
int NetworkPrinter::GetPrintSpeed() const {
    return PrintSpeed;
}
bool NetworkPrinter::GetWiFiSupport() const {
    return WiFiSupport;
}
bool NetworkPrinter::GetBluetoothModule() const {
    return BluetoothModule;
}
int NetworkPrinter::GetPaperCapacity() const {
    return PaperCapacity;
}
NetworkPrinter& NetworkPrinter::operator=(const NetworkPrinter& np) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] Type;
    delete[] MaxResolution;
    delete[] MaxPaperSize;
    delete[] WindowsSupport;
    delete[] Color;
    Name = new char[strlen(np.Name) + 1];
    strcpy(Name, np.Name);
    Manufacturer = new char[strlen(np.Manufacturer) + 1];
    strcpy(Manufacturer, np.Manufacturer);
    Type = new char[strlen(np.Type) + 1];
    strcpy(Type, np.Type);
    MaxResolution = new char[strlen(np.MaxResolution) + 1];
    strcpy(MaxResolution, np.MaxResolution);
    MaxPaperSize = new char[strlen(np.MaxPaperSize) + 1];
    strcpy(MaxPaperSize, np.MaxPaperSize);
    WindowsSupport = new char[strlen(np.WindowsSupport) + 1];
    strcpy(WindowsSupport, np.WindowsSupport);
    Color = new char[strlen(np.Color) + 1];
    strcpy(Color, np.Color);
    ConnectedDeviceCount = np.ConnectedDeviceCount;
    Price = np.Price;
    ColoredType = np.ColoredType;
    PrintSpeed = np.PrintSpeed;
    WiFiSupport = np.WiFiSupport;
    BluetoothModule = np.BluetoothModule;
    PaperCapacity = np.PaperCapacity;
    return *this;
}
void NetworkPrinter::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ConnectedDeviceCount << endl;
    file << Price << endl;
    file << Type << endl;
    file << MaxResolution << endl;
    file << MaxPaperSize << endl;
    file << WindowsSupport << endl;
    file << Color << endl;
    file << ColoredType << endl;
    file << PrintSpeed << endl;
    file << WiFiSupport << endl;
    file << BluetoothModule << endl;
    file << PaperCapacity << endl;
    file.close();
}
void NetworkPrinter::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] Type;
    delete[] MaxResolution;
    delete[] MaxPaperSize;
    delete[] WindowsSupport;
    delete[] Color;
    string tmp;
    getline(file, tmp);
    Name = new char[strlen(tmp.c_str()) + 1];
    strcpy(Name, tmp.c_str());
    getline(file, tmp);
    Manufacturer = new char[strlen(tmp.c_str()) + 1];
    strcpy(Manufacturer, tmp.c_str());
    file >> ConnectedDeviceCount;
    file >> Price;
    getline(file, tmp);
    Type = new char[strlen(tmp.c_str()) + 1];
    strcpy(Type, tmp.c_str());
    getline(file, tmp);
    MaxResolution = new char[strlen(tmp.c_str()) + 1];
    strcpy(MaxResolution, tmp.c_str());
    getline(file, tmp);
    MaxPaperSize = new char[strlen(tmp.c_str()) + 1];
    strcpy(MaxPaperSize, tmp.c_str());
    getline(file, tmp);
    WindowsSupport = new char[strlen(tmp.c_str()) + 1];
    strcpy(WindowsSupport, tmp.c_str());
    getline(file, tmp);
    Color = new char[strlen(tmp.c_str()) + 1];
    strcpy(Color, tmp.c_str());
    file >> ColoredType;
    file >> PrintSpeed;
    file >> WiFiSupport;
    file >> BluetoothModule;
    file >> PaperCapacity;
    file.close();
}
NetworkPrinter::~NetworkPrinter() {
    delete[] Type;
    delete[] MaxResolution;
    delete[] MaxPaperSize;
    delete[] WindowsSupport;
    delete[] Color;
}