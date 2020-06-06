#include "HostComputer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

HostComputer::HostComputer() {
    Name = new char[6];
    strcpy(Name, "Empty");
    Manufacturer = new char[6];
    strcpy(Manufacturer, "Empty");
    ModelCPU = new char[6];
    strcpy(ModelCPU, "Empty");
    MotherboardModel = new char[6];
    strcpy(MotherboardModel, "Empty");
    OS = new char[10];
    strcpy(OS, "Windows 8");
    HardDriveCount = 2;
    RAM = 8;
    PowerSupplyCapacity = 700;
    Price = 20000;
    PerformanceScore = 7300;
    IP = new char[10];
    strcpy(IP, "172.0.0.0");
    Protocol = new char[7];
    strcpy(Protocol, "TCP/IP");
    ConnectedCount = 0;
}
HostComputer::HostComputer(const HostComputer& comp) {
    Name = new char[strlen(comp.Name) + 1];
    strcpy(Name, comp.Name);
    Manufacturer = new char[strlen(comp.Manufacturer) + 1];
    strcpy(Manufacturer, comp.Manufacturer);
    ModelCPU = new char[strlen(comp.ModelCPU) + 1];
    strcpy(ModelCPU, comp.ModelCPU);
    MotherboardModel = new char[strlen(comp.MotherboardModel) + 1];
    strcpy(MotherboardModel, comp.MotherboardModel);
    OS = new char[strlen(comp.OS) + 1];
    strcpy(OS, comp.OS);
    IP = new char[strlen(comp.IP) + 1];
    strcpy(IP, comp.IP);
    Protocol = new char[strlen(comp.Protocol) + 1];
    strcpy(Protocol, comp.Protocol);
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
    ConnectedCount = comp.ConnectedCount;
}
void HostComputer::PrintAllInformation() {
    cout << "Название компьютера: " << Name << endl;
    cout << "Производитель компьютера: " << Manufacturer << endl;
    cout << "Модель процессора: " << ModelCPU << endl;
    cout << "Модель материнской платы: " << MotherboardModel << endl;
    cout << "Операционная система: " << OS << endl;
    cout << "Количество жёстких дисков: " << HardDriveCount << endl;
    cout << "Объём оперативной памяти (Гб): " << RAM << endl;
    cout << "Мощность блока питания: " << PowerSupplyCapacity << endl;
    cout << "Стоимость: " << Price << endl;
    cout << "Оценка производительности: " << PerformanceScore << endl;
    cout << "IP-адрес компьютера: " << IP << endl;
    cout << "Протокол соединения: " << Protocol << endl;
    cout << "Количество подключенных устройств: " << ConnectedCount << endl;
}
HostComputer& HostComputer::operator=(const HostComputer& comp) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] IP;
    delete[] Protocol;
    Name = new char[strlen(comp.Name) + 1];
    strcpy(Name,comp.Name);
    Manufacturer = new char[strlen(comp.Manufacturer) + 1];
    strcpy(Manufacturer, comp.Manufacturer);
    ModelCPU = new char[strlen(comp.ModelCPU) + 1];
    strcpy(ModelCPU, comp.ModelCPU);
    MotherboardModel = new char[strlen(comp.MotherboardModel) + 1];
    strcpy(MotherboardModel, comp.MotherboardModel);
    OS = new char[strlen(comp.OS) + 1];
    strcpy(OS, comp.OS);
    IP = new char[strlen(comp.IP) + 1];
    strcpy(IP, comp.IP);
    Protocol = new char[strlen(comp.Protocol) + 1];
    strcpy(Protocol, comp.Protocol);
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
    ConnectedCount = comp.ConnectedCount;
    return *this;
}
void HostComputer::SetConnectCount(int count) {
    ConnectedCount = count;
}
void HostComputer::SetIP(char* ip) {
    delete[] IP;
    IP = new char[strlen(ip) + 1];
    strcpy(IP, ip);
}
void HostComputer::SetProtocol(char* protocol) {
    delete[] Protocol;
    Protocol = new char[strlen(protocol) + 1];
    strcpy(Protocol, protocol);
}
int HostComputer::GetConnectCount() const {
    return ConnectedCount;
}
char* HostComputer::GetIP()const {
    return IP;
}
char* HostComputer::GetProtocol() const {
    return Protocol;
}
void HostComputer::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ModelCPU << endl;
    file << MotherboardModel << endl;
    file << OS << endl;
    file << IP << endl;
    file << Protocol << endl;
    file << HardDriveCount << endl;
    file << RAM << endl;
    file << PowerSupplyCapacity << endl;
    file << Price << endl;
    file << PerformanceScore << endl;
    file << ConnectedCount << endl;
    file.close();
}
void HostComputer::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] IP;
    delete[] Protocol;
    string tmp;
    getline(file, tmp);
    Name = new char[strlen(tmp.c_str()) + 1];
    strcpy(Name, tmp.c_str());
    getline(file, tmp);
    Manufacturer = new char[strlen(tmp.c_str()) + 1];
    strcpy(Manufacturer, tmp.c_str());
    getline(file, tmp);
    ModelCPU = new char[strlen(tmp.c_str()) + 1];
    strcpy(ModelCPU, tmp.c_str());
    getline(file, tmp);
    MotherboardModel = new char[strlen(tmp.c_str()) + 1];
    strcpy(MotherboardModel, tmp.c_str());
    getline(file, tmp);
    OS = new char[strlen(tmp.c_str()) + 1];
    strcpy(OS, tmp.c_str());
    getline(file, tmp);
    IP = new char[strlen(tmp.c_str()) + 1];
    strcpy(IP, tmp.c_str());
    getline(file, tmp);
    Protocol = new char[strlen(tmp.c_str()) + 1];
    strcpy(Protocol, tmp.c_str());
    file >> HardDriveCount;
    file >> RAM;
    file >> PowerSupplyCapacity;
    file >> Price;
    file >> PerformanceScore;
    file >> ConnectedCount;
    file.close();
}
HostComputer::~HostComputer() {
    delete[] IP;
    delete[] Protocol;
}