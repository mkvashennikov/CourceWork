#pragma once
#include "INetwork.h"
/*
* Класс компьютер. 
* Объекты класса могут описывать любой тип компьютера. 
* Класс содержит поля, которые могут описать основные характеристики компьютера.
* Класс содержит методы, которые могут использоваться для изменения этих характеристик
и их сравнения.
*/
class Computer : public INetwork {
public:
    Computer();
    Computer(const Computer& comp);
    void PrintAllInformation() override;
    double GetPrice() const override;
    char* GetName() const override;
    char* GetManufacturer() const override;
    void SetPrice(double price) override;
    void SetName(char* name) override;
    void SetManufacturer(char* manufacturer) override;
    void SetModelCPU(char* model);
    void SetMotherBoardModel(char* model);
    void SetOS(char* os);
    void SetHardDriveCount(int c);
    void SetRAM(int r);
    void SetPowerSupplyCapacity(int psc);
    void SetPerformanceScore(double ps);
    char* GetModelCPU() const;
    char* GetMotherBoardModel() const;
    char* GetOS() const;
    int GetHardDriveCount() const;
    int GetRAM() const;
    int GetPowerSupplyCapacity() const;
    double GetPerformanceScore() const;
    Computer& operator=(const Computer& comp);
    void WriteToFile(char* path) override;
    void ReadFromFile(char* path) override;
    ~Computer();
protected:
    char* Name;
    char* Manufacturer;
    char* ModelCPU;
    char* MotherboardModel;
    char* OS;
    int HardDriveCount;
    int RAM;
    int PowerSupplyCapacity;
    double Price;
    double PerformanceScore;
};
