#include "ClientNotebook.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ClientNotebook::ClientNotebook() {
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
    Username = new char[7];
    strcpy(Username, "Noname");
    HardDriveCount = 2;
    RAM = 8;
    PowerSupplyCapacity = 500;
    Price = 25000;
    PerformanceScore = 9000;
    WebCamStatus = true;
    BatteryCapacity = 10000;
}
ClientNotebook::ClientNotebook(const ClientNotebook& cn) {
    Name = new char[strlen(cn.Name) + 1];
    strcpy(Name, cn.Name);
    Manufacturer = new char[strlen(cn.Manufacturer) + 1];
    strcpy(Manufacturer, cn.Manufacturer);
    ModelCPU = new char[strlen(cn.ModelCPU) + 1];
    strcpy(ModelCPU, cn.ModelCPU);
    MotherboardModel = new char[strlen(cn.MotherboardModel) + 1];
    strcpy(MotherboardModel, cn.MotherboardModel);
    OS = new char[strlen(cn.OS) + 1];
    strcpy(OS, cn.OS);
    Username = new char[strlen(cn.Username) + 1];
    strcpy(Username, cn.Username);
    HardDriveCount = cn.HardDriveCount;
    RAM = cn.RAM;
    PowerSupplyCapacity = cn.PowerSupplyCapacity;
    Price = cn.Price;
    PerformanceScore = cn.PerformanceScore;
    WebCamStatus = cn.WebCamStatus;
    BatteryCapacity = cn.BatteryCapacity;
}
void ClientNotebook::PrintAllInformation() {
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
    cout << "Имя пользователя: " << Username << endl;
    cout << "Статус вебкамеры: " << WebCamStatus << endl;
    cout << "Ёмкость батареи: " << BatteryCapacity << endl;
}
void ClientNotebook::ChangeWebCamStatus() {
    WebCamStatus = !WebCamStatus;
}
void ClientNotebook::SetWebCamStatus(bool status) {
    WebCamStatus = status;
}
void ClientNotebook::SetBatteryCapacity(double capacity) {
    BatteryCapacity = capacity;
}
bool ClientNotebook::GetWebCamStatus() const {
    return WebCamStatus;
}
double ClientNotebook::GetBatteryCapacity() const {
    return BatteryCapacity;
}
ClientNotebook& ClientNotebook::operator=(const ClientNotebook& cn) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] Username;
    Name = new char[strlen(cn.Name) + 1];
    strcpy(Name, cn.Name);
    Manufacturer = new char[strlen(cn.Manufacturer) + 1];
    strcpy(Manufacturer, cn.Manufacturer);
    ModelCPU = new char[strlen(cn.ModelCPU) + 1];
    strcpy(ModelCPU, cn.ModelCPU);
    MotherboardModel = new char[strlen(cn.MotherboardModel) + 1];
    strcpy(MotherboardModel, cn.MotherboardModel);
    OS = new char[strlen(cn.OS) + 1];
    strcpy(OS, cn.OS);
    Username = new char[strlen(cn.Username) + 1];
    strcpy(Username, cn.Username);
    HardDriveCount = cn.HardDriveCount;
    RAM = cn.RAM;
    PowerSupplyCapacity = cn.PowerSupplyCapacity;
    Price = cn.Price;
    PerformanceScore = cn.PerformanceScore;
    WebCamStatus = cn.WebCamStatus;
    BatteryCapacity = cn.BatteryCapacity;
    return *this;
}
void ClientNotebook::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ModelCPU << endl;
    file << MotherboardModel << endl;
    file << OS << endl;
    file << Username << endl;
    file << HardDriveCount << endl;
    file << RAM << endl;
    file << PowerSupplyCapacity << endl;
    file << Price << endl;
    file << PerformanceScore << endl;
    file << WebCamStatus << endl;
    file << BatteryCapacity << endl;
    file.close();
}
void ClientNotebook::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] Username;
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
    Username = new char[strlen(tmp.c_str()) + 1];
    strcpy(Username, tmp.c_str());
    file >> HardDriveCount;
    file >> RAM;
    file >> PowerSupplyCapacity;
    file >> Price;
    file >> PerformanceScore;
    file >> WebCamStatus;
    file >> BatteryCapacity;
    file.close();
}
