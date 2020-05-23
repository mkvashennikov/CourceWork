#include "NetworkAdapter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

NetworkAdapter::NetworkAdapter() {
    Type = new char[7];
    strcpy(Type, "NoType");
    WiFiProtocol = new char[4];
    strcpy(WiFiProtocol, "PNP");
    InterfaceConnect = new char[4];
    strcpy(InterfaceConnect, "PCI");
    MACAdress = new char[8];
    strcpy(MACAdress, "0.0.2.0");
    Speed = 100;
    CountAntennas = 1;
    NetworkMedia = true;
}
NetworkAdapter::NetworkAdapter(const NetworkAdapter& na) {
    Name = new char[strlen(na.Name) + 1];
    strcpy(Name, na.Name);
    Manufacturer = new char[strlen(na.Manufacturer) + 1];
    strcpy(Manufacturer, na.Manufacturer);
    Type = new char[strlen(na.Type) + 1];
    strcpy(Type, na.Type);
    WiFiProtocol = new char[strlen(na.WiFiProtocol) + 1];
    strcpy(WiFiProtocol, na.WiFiProtocol);
    InterfaceConnect = new char[strlen(na.InterfaceConnect) + 1];
    strcpy(InterfaceConnect, na.InterfaceConnect);
    MACAdress = new char[strlen(na.MACAdress) + 1];
    strcpy(MACAdress, na.MACAdress);
    ConnectedDeviceCount = na.ConnectedDeviceCount;
    Price = na.Price;
    Speed = na.Speed;
    CountAntennas = na.CountAntennas;
    NetworkMedia = na.NetworkMedia;
}
void NetworkAdapter::PrintAllInformation() {
    cout << "Название устройства: " << Name << endl;
    cout << "Производитель устройства: " << Manufacturer << endl;
    cout << "Количество подключенных устройств: " << ConnectedDeviceCount << endl;
    cout << "Стоимость: " << Price << endl;
    cout << "Тип: " << Type << endl;
    cout << "Протокол Wi-Fi: " << WiFiProtocol << endl;
    cout << "Интерфейс подключения: " << InterfaceConnect << endl;
    cout << "Mac-адрес: " << MACAdress << endl;
    cout << "Скорость: " << Speed << endl;
    cout << "Количество антенн: " << CountAntennas << endl;
    cout << "Сетевые медиа-устройства: " << NetworkMedia << endl;
}
void NetworkAdapter::SetType(char* tp) {
    delete[] Type;
    Type = new char[strlen(tp) + 1];
    strcpy(Type, tp);
}
void NetworkAdapter::SetWiFiProtocol(char* pr) {
    delete[] WiFiProtocol;
    WiFiProtocol = new char[strlen(pr) + 1];
    strcpy(WiFiProtocol, pr);
}
void NetworkAdapter::SetMACAdress(char* mc) {
    delete[] MACAdress;
    MACAdress = new char[strlen(mc) + 1];
    strcpy(MACAdress, mc);
}
void NetworkAdapter::SetIntefaceConnect(char* interface) {
    delete[] InterfaceConnect;
    InterfaceConnect = new char[strlen(interface) + 1];
    strcpy(InterfaceConnect, interface);
}
void NetworkAdapter::SetSpeed(double sp) {
    Speed = sp;
}
void NetworkAdapter::SetCountAntennas(int a) {
    CountAntennas = a;
}
void NetworkAdapter::ChangeNetworkMedia(bool nm) {
    NetworkMedia = nm;
}
char* NetworkAdapter::GetType() const {
    return Type;
}
char* NetworkAdapter::GetWiFiProtocol() const {
    return WiFiProtocol;
}
char* NetworkAdapter::GetIntefaceConnect() const {
    return InterfaceConnect;
}
char* NetworkAdapter::GetMACAdress() const {
    return MACAdress;
}
double NetworkAdapter::GetSpeed() const {
    return Speed;
}
int NetworkAdapter::GetCountAntennas() const {
    return CountAntennas;
}
bool NetworkAdapter::GetNetworkMedia() const {
    return NetworkMedia;
}
NetworkAdapter& NetworkAdapter::operator=(const NetworkAdapter& na) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] Type;
    delete[] WiFiProtocol;
    delete[] InterfaceConnect;
    delete[] MACAdress;
    Name = new char[strlen(na.Name)+1];
    strcpy(Name,na.Name);
    Manufacturer = new char[strlen(na.Manufacturer) + 1];
    strcpy(Manufacturer, na.Manufacturer);
    Type = new char[strlen(na.Type) + 1];
    strcpy(Type, na.Type);
    WiFiProtocol = new char[strlen(na.WiFiProtocol) + 1];
    strcpy(WiFiProtocol, na.WiFiProtocol);
    InterfaceConnect = new char[strlen(na.InterfaceConnect) + 1];
    strcpy(InterfaceConnect, na.InterfaceConnect);
    MACAdress = new char[strlen(na.MACAdress) + 1];
    strcpy(MACAdress, na.MACAdress);
    ConnectedDeviceCount = na.ConnectedDeviceCount;
    Price = na.Price;
    Speed = na.Speed;
    CountAntennas = na.CountAntennas;
    NetworkMedia = na.NetworkMedia;
    return *this;
}
void NetworkAdapter::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ConnectedDeviceCount << endl;
    file << Price << endl;
    file << Type << endl;
    file << WiFiProtocol << endl;
    file << InterfaceConnect << endl;
    file << MACAdress << endl;
    file << Speed << endl;
    file << CountAntennas << endl;
    file << NetworkMedia << endl;
    file.close();
}
void NetworkAdapter::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] Type;
    delete[] WiFiProtocol;
    delete[] InterfaceConnect;
    delete[] MACAdress;
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
    WiFiProtocol = new char[strlen(tmp.c_str()) + 1];
    strcpy(WiFiProtocol, tmp.c_str());
    getline(file, tmp);
    InterfaceConnect = new char[strlen(tmp.c_str()) + 1];
    strcpy(InterfaceConnect, tmp.c_str());
    getline(file, tmp);
    MACAdress = new char[strlen(tmp.c_str()) + 1];
    strcpy(MACAdress, tmp.c_str());
    file >> Speed;
    file >> CountAntennas;
    file >> NetworkMedia;
    file.close();
}
NetworkAdapter::~NetworkAdapter() {
    delete[] Type;
    delete[] WiFiProtocol;
    delete[] InterfaceConnect;
    delete[] MACAdress;
}