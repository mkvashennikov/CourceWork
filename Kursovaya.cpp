#include <iostream>
#include <string>
#include "Exception.h"
#include "Vector.h";
#include "HostComputer.h"
#include "Server.h"
#include "ClientNotebook.h"
#include "ClientPC.h"
#include "NetworkAdapter.h"
#include "NetworkPrinter.h"
using namespace std;

//Функция проверяет ошибочный ввод числа в консоль и бросает исключение в случае ошибки.
void isNumeric() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw Exception("Вы ввели неверное число!");
    }
}
//Внешняя функция для сравнения всех объектов по стоимости (используется при сортировке)
template<class T>
bool CompareByPrice(const T& comp1, const T& comp2) {
    if (comp1->GetPrice() > comp2->GetPrice()) return true;
    return false;
}
//Внешняя функция для сравнения всех объектов по производительности (используется при сортировке)
template<class T>
bool CompareByPerformance(const T& comp1, const T& comp2) {
    if (dynamic_cast<Computer*>(comp1)->GetPerformanceScore() > 
        dynamic_cast<Computer*>(comp2)->GetPerformanceScore()) return true;
    return false;
}
//Внешняя функция для поиска одного объекта по стоимости (используется при поиске)
template<class T>
bool FinderByPrice(double value, const T& comp) {
    if (value == comp->GetPrice()) return true;
    return false;
}
//Внешняя функция для поиска всех объектов по стоимости (используется при поиске)
template<class T>
bool FinderAllByPrice(double min, double max, const T& comp) {
    if (comp->GetPrice() >= min && comp->GetPrice() <= max) return true;
    return false;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    int choise = 0, choise2 = 0;
    Vector<INetwork*> vec;
    while (true) {
        cout << "Выберите желаемое дейтствие: " << endl;
        cout << "1 - Добавить объект" << endl;
        cout << "2 - Редактировать существующий объект" << endl;
        cout << "3 - Удалить объект" << endl;
        cout << "4 - Отсортировать элементы по цене" << endl;
        cout << "5 - Вывод полной информации об объекте" << endl;
        cout << "6 - Вывод названий всех объектов" << endl;
        cout << "7 - Поиск объекта" << endl;
        cout << "8 - Поиск объектов по диапазону" << endl;
        cout << "9 - Запись в файл" << endl;
        cout << "10 - Чтение из файла" << endl;
        cout << "11 - Выйти из программы" << endl;
        cin >> choise;
        system("cls");
        if (choise == 1 || choise == 2) {
            cout << "Выберите класс для работы: " << endl;
            cout << "1 - Компьютер" << endl;
            cout << "2 - Компьютер-хост" << endl;
            cout << "3 - Клиентский компьютер" << endl;
            cout << "4 - Ноутбук" << endl;
            cout << "5 - Персональный компьютер" << endl;
            cout << "6 - Сервер" << endl;
            cout << "7 - Сетевое устройство" << endl;
            cout << "8 - Сетевой адаптер" << endl;
            cout << "9 - Сетевой принтер" << endl;
            cout << "10 - Выйти из программы" << endl;
        }
        int n;
        string tmp;
        int col = 0;
        double var = 0.0;
        try {
            switch (choise)
            {
            case 1:
            {
                cin >> choise2;
                switch (choise2)
                {
                case 1:
                {
                    vec.PushBack(new Computer());
                    break;
                }
                case 2:
                {
                    vec.PushBack(new HostComputer());
                    break;
                }
                case 3:
                {
                    vec.PushBack(new ClientComputer());
                    break;
                }
                case 4:
                {
                    vec.PushBack(new ClientNotebook());
                    break;
                }
                case 5:
                {
                    vec.PushBack(new ClientPC());
                    break;
                }
                case 6:
                {
                    vec.PushBack(new Server());
                    break;
                }
                case 7:
                {
                    vec.PushBack(new NetworkDevice());
                    break;
                }
                case 8:
                {
                    vec.PushBack(new NetworkAdapter());
                    break;
                }
                case 9:
                {
                    vec.PushBack(new NetworkPrinter());
                    break;
                }
                default:
                    return 0;
                }
            }
            case 2:
            {
                if (choise2 == 0) cin >> choise2;
                switch (choise2)
                {
                case 1:
                {
                    cout << "Задать название компьютеру: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<Computer*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    break;
                    break;
                }
                case 2:
                {
                    cout << "Задать название компьютеру: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить IP-адрес: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetIP((char*)tmp.c_str());
                    cout << "Изменить протокол подключения: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetProtocol((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    cout << "Изменить кол-во подключенных устройств: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<HostComputer*>(vec[vec.Length() - 1])->SetConnectCount(col);
                    break;
                }
                case 3:
                {
                    cout << "Задать название компьютеру: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить имя пользователя: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetUsername((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<ClientComputer*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    break;
                }
                case 4:
                {
                    cout << "Задать название ноутбуку: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить имя пользователя: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetUsername((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    cout << "Изменить статус вебкамеры: " << endl;
                    cout << "1 - Вкл" << endl;
                    cout << "2 - Выкл" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetWebCamStatus(true);
                    else dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetWebCamStatus(false);
                    cout << "Изменить ёмкость батареи: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<ClientNotebook*>(vec[vec.Length() - 1])->SetBatteryCapacity(var);
                    break;
                }
                case 5:
                {
                    cout << "Задать название компьютеру: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить имя пользователя: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetUsername((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    cout << "Является ли ОС лицензионной?" << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetLicencedOS(true);
                    else dynamic_cast<ClientPC*>(vec[vec.Length() - 1])->SetLicencedOS(false);
                    break;
                }
                case 6:
                {
                    cout << "Задать название серверу: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить модель процессора: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetModelCPU((char*)tmp.c_str());
                    cout << "Изменить модель материнской платы: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetMotherBoardModel((char*)tmp.c_str());
                    cout << "Изменить операционную систему: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetOS((char*)tmp.c_str());
                    cout << "Изменить администратора сервера: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetAdmin((char*)tmp.c_str());
                    cout << "Изменить количество жёстких дисков: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetHardDriveCount(col);
                    cout << "Изменить количество оперативной памяти (Гб): " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetRAM(col);
                    cout << "Изменить мощность блока питания: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetPowerSupplyCapacity(col);
                    cout << "Изменить цену: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить оценку производительности: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<Server*>(vec[vec.Length() - 1])->SetPerformanceScore(var);
                    break;
                }
                case 7:
                {
                    cout << "Задать название устройству: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить цену устройства: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить количество подключенных устройств: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkDevice*>(vec[vec.Length() - 1])->SetConnectedDeviceCount(col);
                    break;
                }
                case 8:
                {
                    cout << "Задать название устройству: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить тип устройства: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetType((char*)tmp.c_str());
                    cout << "Изменить Wi-Fi протокол: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetWiFiProtocol((char*)tmp.c_str());
                    cout << "Изменить интерфейс подключения: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetIntefaceConnect((char*)tmp.c_str());
                    cout << "Изменить Mac-адрес: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetMACAdress((char*)tmp.c_str());
                    cout << "Изменить цену устройства: " << endl;
                    cin >> var;
                    isNumeric();
                    vec[vec.Length() - 1]->SetPrice(var);
                    cout << "Изменить количество подключенных устройств: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetConnectedDeviceCount(col);
                    cout << "Изменить скорость устройства: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetSpeed(var);
                    cout << "Изменить количество антенн: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->SetCountAntennas(col);
                    cout << "Изменить сетевое медиа: " << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->ChangeNetworkMedia(true);
                    else dynamic_cast<NetworkAdapter*>(vec[vec.Length() - 1])->ChangeNetworkMedia(false);
                    break;
                }
                case 9:
                {
                    cout << "Задать название принтеру: " << endl;
                    cin.get();
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetName((char*)tmp.c_str());
                    cout << "Изменить производителя: " << endl;
                    getline(cin, tmp);
                    vec[vec.Length() - 1]->SetManufacturer((char*)tmp.c_str());
                    cout << "Изменить тип принтера: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetType((char*)tmp.c_str());
                    cout << "Изменить максимальное разрешение печати: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetMaxResolution((char*)tmp.c_str());
                    cout << "Изменить максимальный размер листа: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetMaxPaperSize((char*)tmp.c_str());
                    cout << "Какой Windows поддерживает: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetWindowsSupport((char*)tmp.c_str());
                    cout << "Изменить цвет принтера: " << endl;
                    getline(cin, tmp);
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetColor((char*)tmp.c_str());
                    cout << "Изменить цену принтера: " << endl;
                    cin >> var;
                    isNumeric();
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetPrice(var);
                    cout << "Изменить количество подключенных устройств: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetConnectedDeviceCount(col);
                    cout << "Изменить скорость печати: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetPrintSpeed(col);
                    cout << "Изменить вместимость листов: " << endl;
                    cin >> col;
                    isNumeric();
                    dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetPaperCapacity(col);
                    cout << "Цветной принтер или нет: " << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetColorType(true);
                    else dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetColorType(false);
                    cout << "Есть ли поддержка Wi-Fi: " << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetWiFiSupport(true);
                    else dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetWiFiSupport(false);
                    cout << "Есть ли Bluetooth модуль: " << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    cin >> col;
                    isNumeric();
                    if (col == 1) dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetBlueToothModule(true);
                    else dynamic_cast<NetworkPrinter*>(vec[vec.Length() - 1])->SetBlueToothModule(false);
                    break;
                }
                default:
                    return 0;
                }
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec.Erase(n);
                break;
            }
            case 4:
            {
                if (vec.Length() == 0) throw Exception("Нечего сортировать!");
                vec.ComparableSort(CompareByPrice);
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec[n]->PrintAllInformation();
                break;
            }
            case 6:
            {
                if (vec.Length() <= 0) cout << "У вас ещё нет объектов." << endl;
                for (int i = 0; i < vec.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec[i]->GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти (будет найден первый элемент):" << endl;
                cin >> var;
                INetwork** temp = vec.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else (*temp)->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость объектов: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость объектов: " << endl;
                cin >> max;
                Vector<INetwork*>* find = vec.Search(min, max, FinderAllByPrice);
                if (find == nullptr) cout << "Вашего элемента не существует..." << endl;
                else {
                    cout << "Ваши найденные элементы: " << endl;
                    for (int i = 0; i < find->Length(); i++) {
                        cout << "#" << i + 1 << " " << (*find)[i]->GetName() << endl;
                    }
                    delete find;
                }
                break;
            }
            case 9:
            {
                cout << "Укажите номер объекта, который хотите записать в файл" << endl;
                cin >> n;
                isNumeric();
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec[n]->WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                cout << "Какой класс представляет файл?" << endl;
                cout << "1 - Компьютер" << endl;
                cout << "2 - Компьютер-хост" << endl;
                cout << "3 - Клиентский компьютер" << endl;
                cout << "4 - Ноутбук" << endl;
                cout << "5 - Персональный компьютер" << endl;
                cout << "6 - Сервер" << endl;
                cout << "7 - Сетевое устройство" << endl;
                cout << "8 - Сетевой адаптер" << endl;
                cout << "9 - Сетевой принтер" << endl;
                cin >> choise2;
                INetwork* temp;
                switch (choise2) {
                case 1:
                    vec.PushBack(new Computer());
                    break;
                case 2:
                    vec.PushBack(new HostComputer());
                    break;
                case 3:
                    vec.PushBack(new ClientComputer());
                    break;
                case 4:
                    vec.PushBack(new ClientNotebook());
                    break;
                case 5:
                    vec.PushBack(new ClientPC());
                    break;
                case 6:
                    vec.PushBack(new Server());
                    break;
                case 7:
                    vec.PushBack(new NetworkDevice());
                    break;
                case 8:
                    vec.PushBack(new NetworkAdapter());
                    break;
                case 9:
                    vec.PushBack(new NetworkPrinter());
                    break;
                default:
                    return 0;
                }
                if (vec.Length()) vec[vec.Length() - 1]->ReadFromFile((char*)tmp.c_str());
                else cout << "Нет элементов в векторе!" << endl;
                break;
            }
            default:
                return 0;
            }
        }
        catch (Exception& ex) {
            cout << "<---------------ОШИБКА!-------------->" << endl;
            cout << ex.GetError() << endl;
            cout << "<------------------------------------>" << endl << endl;
        }
    }
    system("pause");
    return 0;
}
