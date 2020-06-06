#include "ClientPC.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ClientPC::ClientPC() {
    Name = new char[6];
    strcpy(Name, "Empty");
    Manufacturer = new char[6];
    strcpy(Manufacturer, "Empty");
    ModelCPU = new char[6];
    strcpy(ModelCPU, "Empty");
    MotherboardModel = new char[6];
    strcpy(MotherboardModel, "Empty");
    OS = new char[10];
    strcpy(OS, "Windows 7");
    Username = new char[7];
    strcpy(Username, "Noname");
    HardDriveCount = 2;
    RAM = 12;
    PowerSupplyCapacity = 800;
    Price = 21200;
    PerformanceScore = 8000;
    LicencedOS = true;
}
ClientPC::ClientPC(const ClientPC& comp) {
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
    Username = new char[strlen(comp.Username) + 1];
    strcpy(Username, comp.Username);
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
    LicencedOS = comp.LicencedOS;
}
void ClientPC::PrintAllInformation() {
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
    cout << "Операционная система с лицензией: " << LicencedOS << endl;
}
void ClientPC::SetLicencedOS(bool licenced) {
    LicencedOS = licenced;
}
bool ClientPC::GetLicencedOS() const {
    return LicencedOS;
}
ClientPC& ClientPC::operator=(const ClientPC& comp) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
    delete[] Username;
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
    Username = new char[strlen(comp.Username) + 1];
    strcpy(Username, comp.Username);
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
    LicencedOS = comp.LicencedOS;
    return *this;
}
void ClientPC::WriteToFile(char* path) {
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
    file << LicencedOS << endl;
    file.close();
}
void ClientPC::ReadFromFile(char* path) {
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
    file >> LicencedOS;
    file.close();
}