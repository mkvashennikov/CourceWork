#include "NetworkDevice.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

NetworkDevice::NetworkDevice() {
    Name = new char[6];
    strcpy(Name, "Empty");
    Manufacturer = new char[6];
    strcpy(Manufacturer, "Empty");
    ConnectedDeviceCount = 2;
    Price = 5623.53;
}
NetworkDevice::NetworkDevice(const NetworkDevice& nd) {
    Name = new char[strlen(nd.Name) + 1];
    strcpy(Name, nd.Name);
    Manufacturer = new char[strlen(nd.Manufacturer) + 1];
    strcpy(Manufacturer, nd.Manufacturer);
    ConnectedDeviceCount = nd.ConnectedDeviceCount;
    Price = nd.Price;
}
void NetworkDevice::PrintAllInformation() {
    cout << "Название устройства: " << Name << endl;
    cout << "Производитель устройства: " << Manufacturer << endl;
    cout << "Количество подключенных устройств: " << ConnectedDeviceCount << endl;
    cout << "Стоимость: " << Price << endl;
}
double NetworkDevice::GetPrice() const {
    return Price;
}
char* NetworkDevice::GetName() const {
    return Name;
}
char* NetworkDevice::GetManufacturer() const {
    return Manufacturer;
}
void NetworkDevice::SetPrice(double price) {
    Price = price;
}
void NetworkDevice::SetName(char* name) {
    delete[] Name;
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
}
void NetworkDevice::SetManufacturer(char* mn) {
    delete[] Manufacturer;
    Manufacturer = new char[strlen(mn) + 1];
    strcpy(Manufacturer, mn);
}
void NetworkDevice::SetConnectedDeviceCount(int c) {
    ConnectedDeviceCount = c;
}
int NetworkDevice::GetConnectedDeviceCount() const {
    return ConnectedDeviceCount;
}
NetworkDevice::~NetworkDevice() {
    delete[] Name;
    delete[] Manufacturer;
}
NetworkDevice& NetworkDevice::operator=(const NetworkDevice& nd) {
    delete[] Name;
    delete[] Manufacturer;
    Name = new char[strlen(nd.Name)+1];
    strcpy(Name,nd.Name);
    Manufacturer = new char[strlen(nd.Manufacturer) + 1];
    strcpy(Manufacturer, nd.Manufacturer);
    ConnectedDeviceCount = nd.ConnectedDeviceCount;
    Price = nd.Price;
    return *this;
}
void NetworkDevice::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ConnectedDeviceCount << endl;
    file << Price << endl;
    file.close();
}
void NetworkDevice::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    string tmp;
    getline(file, tmp);
    Name = new char[strlen(tmp.c_str()) + 1];
    strcpy(Name, tmp.c_str());
    getline(file, tmp);
    Manufacturer = new char[strlen(tmp.c_str()) + 1];
    strcpy(Manufacturer, tmp.c_str());
    file >> ConnectedDeviceCount;
    file >> Price;
    file.close();
}