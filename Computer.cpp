#include "Computer.h"
#include <iostream>
#include <fstream>
#include "HostComputer.h"
#include <string>
using namespace std;

Computer::Computer() {
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
    HardDriveCount = 1;
    RAM = 4;
    PowerSupplyCapacity = 500;
    Price = 14000;
    PerformanceScore = 5000;
}
Computer::Computer(const Computer& comp) {
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
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
}
void Computer::PrintAllInformation() {
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
}
void Computer::SetModelCPU(char* model) {
    delete[] ModelCPU;
    ModelCPU = new char[strlen(model)+1];
    strcpy(ModelCPU,model);
}
void Computer::SetMotherBoardModel(char* model) {
    delete[] MotherboardModel;
    MotherboardModel = new char[strlen(model) + 1];
    strcpy(MotherboardModel, model);
}
void Computer::SetOS(char* os) {
    delete[] OS;
    OS = new char[strlen(os) + 1];
    strcpy(OS, os);
}
void Computer::SetHardDriveCount(int c) {
    HardDriveCount = c;
}
void Computer::SetRAM(int r) {
    RAM = r;
}
void Computer::SetPowerSupplyCapacity(int psc) {
    PowerSupplyCapacity = psc;
}
void Computer::SetPerformanceScore(double ps) {
    PerformanceScore = ps;
}
char* Computer::GetModelCPU() const {
    return ModelCPU;
}
char* Computer::GetMotherBoardModel() const {
    return MotherboardModel;
}
char* Computer::GetOS() const {
    return OS;
}
int Computer::GetHardDriveCount() const {
    return HardDriveCount;
}
int Computer::GetRAM() const {
    return RAM;
}
int Computer::GetPowerSupplyCapacity() const {
    return PowerSupplyCapacity;
}
double Computer::GetPerformanceScore() const {
    return PerformanceScore;
}
double Computer::GetPrice() const {
    return Price;
}
char* Computer::GetName() const {
    return Name;
}
char* Computer::GetManufacturer() const {
    return Manufacturer;
}
void Computer::SetPrice(double price) {
    Price = price;
}
void Computer::SetName(char* name) {
    delete[] Name;
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
}
void Computer::SetManufacturer(char* manufacturer) {
    delete[] Manufacturer;
    Manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(Manufacturer, manufacturer);
}
Computer& Computer::operator=(const Computer& comp) {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
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
    HardDriveCount = comp.HardDriveCount;
    RAM = comp.RAM;
    PowerSupplyCapacity = comp.PowerSupplyCapacity;
    Price = comp.Price;
    PerformanceScore = comp.PerformanceScore;
    return *this;
}
void Computer::WriteToFile(char* path) {
    ofstream file(path);
    file << Name << endl;
    file << Manufacturer << endl;
    file << ModelCPU << endl;
    file << MotherboardModel << endl;
    file << OS << endl;
    file << HardDriveCount << endl;
    file << RAM << endl;
    file << PowerSupplyCapacity << endl;
    file << Price << endl;
    file << PerformanceScore << endl;
    file.close();
}
void Computer::ReadFromFile(char* path) {
    ifstream file(path);
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
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
    file >> HardDriveCount;
    file >> RAM;
    file >> PowerSupplyCapacity;
    file >> Price;
    file >> PerformanceScore;
    file.close();
}
Computer::~Computer() {
    delete[] Name;
    delete[] Manufacturer;
    delete[] ModelCPU;
    delete[] MotherboardModel;
    delete[] OS;
}