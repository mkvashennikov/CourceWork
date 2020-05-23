#pragma once
/*
*Класс-интерфейс, состоящий только из чисто виртуальных методов.
*Предназначен для того, чтобы наследники данного класса гарантированно реализовывали его методы.
*/
class INetwork {
public:
    virtual void PrintAllInformation() = 0;
    virtual double GetPrice() const = 0;
    virtual char* GetName() const = 0;
    virtual char* GetManufacturer() const = 0;
    virtual void SetPrice(double price) = 0;
    virtual void SetName(char* name) = 0;
    virtual void SetManufacturer(char* manufacturer) = 0;
    virtual void WriteToFile(char* path) = 0;
    virtual void ReadFromFile(char* path) = 0;
};