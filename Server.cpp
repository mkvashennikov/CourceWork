#include "Server.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
Server::Server() {
    Name = new char[6];
    strcpy(Name, "Empty");
    Manufacturer = new char[6];
    strcpy(Manufacturer, "Empty");
    ModelCPU = new char[6];
    strcpy(ModelCPU, "Empty");
    MotherboardModel = new char[6];
    strcpy(MotherboardModel, "Empty");
    OS = new char[11];
    strcpy(OS, "Windows 10");
    Admin = new char[14];
    strcpy(Admin, "Administrator");
    HardDriveCount = 10;
    RAM = 32;
    PowerSupplyCapacity = 1000;
    Price = 50000;
    PerformanceScore = 15000;
}
Server::Server(const Server& serv) {
    Name = new char[strlen(serv.Name) + 1];
    strcpy(Name, serv.Name);
    Manufacturer = new char[strlen(serv.Manufacturer) + 1];
    strcpy(Manufacturer, serv.Manufacturer);
    ModelCPU = new char[strlen(serv.ModelCPU) + 1];
    strcpy(ModelCPU, serv.ModelCPU);
    MotherboardModel = new char[strlen(serv.MotherboardModel) + 1];
    strcpy(MotherboardModel, serv.MotherboardModel);
    OS = new char[strlen(serv.OS) + 1];
    strcpy(OS, serv.OS);
    Admin = new char[strlen(serv.Admin) + 1];
    strcpy(Admin, serv.Admin);
    HardDriveCount = serv.HardDriveCount;
    RAM = serv.RAM;
    PowerSupplyCapacity = serv.PowerSupplyCapacity;
    Price = serv.Price;
    PerformanceScore = serv.PerformanceScore;
}
void Server::PrintAllInformation() {
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
    cout << "Администратор сервера: " << Admin << endl;
}
Server& Server::operator=(const Server& serv) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] Admin;
    Name = new char[strlen(serv.Name)+1];
    strcpy(Name, serv.Name);
    Manufacturer = new char[strlen(serv.Manufacturer) + 1];
    strcpy(Manufacturer, serv.Manufacturer);
    ModelCPU = new char[strlen(serv.ModelCPU) + 1];
    strcpy(ModelCPU, serv.ModelCPU);
    MotherboardModel = new char[strlen(serv.MotherboardModel) + 1];
    strcpy(MotherboardModel, serv.MotherboardModel);
    OS = new char[strlen(serv.OS) + 1];
    strcpy(OS, serv.OS);
    Admin = new char[strlen(serv.Admin) + 1];
    strcpy(Admin, serv.Admin);
    HardDriveCount = serv.HardDriveCount;
    RAM = serv.RAM;
    PowerSupplyCapacity = serv.PowerSupplyCapacity;
    Price = serv.Price;
    PerformanceScore = serv.PerformanceScore;
    return *this;
}
void Server::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ModelCPU << endl;
    file << MotherboardModel << endl;
    file << OS << endl;
    file << Admin << endl;
    file << HardDriveCount << endl;
    file << RAM << endl;
    file << PowerSupplyCapacity << endl;
    file << Price << endl;
    file << PerformanceScore << endl;
    file.close();
}
void Server::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] Admin;
    string tmp;
    getline(file, tmp);
    Name = new char[strlen(tmp.c_str())+1];
    strcpy(Name,tmp.c_str());
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
    Admin = new char[strlen(tmp.c_str()) + 1];
    strcpy(Admin, tmp.c_str());
    file >> HardDriveCount;
    file >> RAM;
    file >> PowerSupplyCapacity;
    file >> Price;
    file >> PerformanceScore;
    file.close();
}
void Server::SetAdmin(char* admin) {
    delete[] Admin;
    Admin = new char[strlen(admin) + 1];
    strcpy(Admin, admin);
}
char* Server::GetAdmin() const {
    return Admin;
}
Server::~Server() {
    delete[] Admin;
}