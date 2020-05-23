#include <iostream>
#include <string>
#include "Exception.h"
#include "Vector.h";
#include "Computer.h"
#include "HostComputer.h"
#include "ClientComputer.h"
#include "Server.h"
#include "ClientNotebook.h"
#include "ClientPC.h"
#include "NetworkDevice.h"
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
    if (comp1.GetPrice() > comp2.GetPrice()) return true;
    return false;
}
//Внешняя функция для сравнения всех объектов по производительности (используется при сортировке)
template<class T>
bool CompareByPerformance(const T& comp1, const T& comp2) {
    if (comp1.GetPerformanceScore() > comp2.GetPerformanceScore()) return true;
    return false;
}
//Внешняя функция для поиска одного объекта по стоимости (используется при поиске)
template<class T>
bool FinderByPrice(double value, const T& comp) {
    if (value == comp.GetPrice()) return true;
    return false;
}
//Внешняя функция для поиска всех объектов по стоимости (используется при поиске)
template<class T>
bool FinderAllByPrice(double min, double max, const T& comp) {
    if (comp.GetPrice() > min&& comp.GetPrice() < max) return true;
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise, choise2;
    Vector<Computer> vec1;
    Vector<HostComputer> vec2;
    Vector<ClientComputer> vec3;
    Vector<Server> vec4;
    Vector<ClientNotebook> vec5;
    Vector<ClientPC> vec6;
    Vector<NetworkDevice> vec7;
    Vector<NetworkAdapter> vec8;
    Vector<NetworkPrinter> vec9;
    while (true) {
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
        cin >> choise;
        if (choise == 10) return 0;
        system("cls");
        cout << "Какое действие хотите выполнить с классом?" << endl;
        cout << "1 - Добавить объект" << endl;
        cout << "2 - Редактировать существующий объект" << endl;
        cout << "3 - Удалить объект" << endl;
        cout << "4 - Отсортировать элементы" << endl;
        cout << "5 - Вывод полной информации об объекте" << endl;
        cout << "6 - Вывод названий всех объектов" << endl;
        cout << "7 - Поиск объекта" << endl;
        cout << "8 - Поиск объектов по диапазону" << endl;
        cout << "9 - Запись в файл" << endl;
        cout << "10 - Чтение из файла" << endl;
        cout << "11 - Выйти из программы" << endl;
        int n;
        string tmp;
        int col = 0;
        double var = 0.0;
        try {
        switch (choise)
        {
        case 1:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                Computer* comp = new Computer;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                vec1.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                vec1[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec1[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec1[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec1[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec1[n].SetOS((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec1[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec1[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec1[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec1[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec1[n].SetPerformanceScore(var);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec1.Erase(n);
                break;
            }
            case 4:
            {
                if (vec1.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec1.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec1.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec1[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec1.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec1[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                Computer* temp = vec1.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<Computer>* find = vec1.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec1[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec1.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec1[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    Computer* comp = new Computer;
                    vec1.PushBack(*comp);
                    vec1[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 2:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                HostComputer* comp = new HostComputer;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить IP-адрес: " << endl;
                getline(cin, tmp);
                comp->SetIP((char*)tmp.c_str());
                cout << "Изменить протокол подключения: " << endl;
                getline(cin, tmp);
                comp->SetProtocol((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                cout << "Изменить кол-во подключенных устройств: " << endl;
                cin >> var;
                isNumeric();
                comp->SetConnectCount(col);
                vec2.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                vec2[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec2[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec2[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec2[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec2[n].SetOS((char*)tmp.c_str());
                cout << "Изменить IP-адрес: " << endl;
                getline(cin, tmp);
                vec2[n].SetIP((char*)tmp.c_str());
                cout << "Изменить протокол подключения: " << endl;
                getline(cin, tmp);
                vec2[n].SetProtocol((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec2[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec2[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec2[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec2[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec2[n].SetPerformanceScore(var);
                cout << "Изменить кол-во подключенных устройств: " << endl;
                cin >> var;
                isNumeric();
                vec2[n].SetConnectCount(col);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec2.Erase(n);
                break;
            }
            case 4:
            {
                if (vec2.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec2.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec2.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec2[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec2.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec2[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                HostComputer* temp = vec2.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<HostComputer>* find = vec2.Search(min, max,FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec2[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec2.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec2[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    HostComputer* comp = new HostComputer;
                    vec2.PushBack(*comp);
                    vec2[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 3:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                ClientComputer* comp = new ClientComputer;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                comp->SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                vec3.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                vec3[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec3[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec3[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec3[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec3[n].SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                vec3[n].SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec3[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec3[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec3[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec3[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec3[n].SetPerformanceScore(var);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec3.Erase(n);
                break;
            }
            case 4:
            {
                if (vec3.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec3.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec3.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec3[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec3.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec3[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                ClientComputer* temp = vec3.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<ClientComputer>* find = vec3.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec3[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec3.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec3[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    ClientComputer* comp = new ClientComputer;
                    vec3.PushBack(*comp);
                    vec3[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 4:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                ClientNotebook* comp = new ClientNotebook;
                cout << "Задать название ноутбуку: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                comp->SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                cout << "Изменить статус вебкамеры: " << endl;
                cout << "1 - Вкл" << endl;
                cout << "2 - Выкл" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->SetWebCamStatus(true);
                else comp->SetWebCamStatus(false);
                cout << "Изменить ёмкость батареи: " << endl;
                cin >> var;
                isNumeric();
                comp->SetBatteryCapacity(var);
                vec5.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название ноутбуку: " << endl;
                cin.get();
                getline(cin, tmp);
                vec5[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec5[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec5[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec5[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec5[n].SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                vec5[n].SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec5[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec5[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec5[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec5[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec5[n].SetPerformanceScore(var);
                cout << "Изменить статус вебкамеры: " << endl;
                cout << "1 - Вкл" << endl;
                cout << "2 - Выкл" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) vec5[n].SetWebCamStatus(true);
                else vec5[n].SetWebCamStatus(false);
                cout << "Изменить ёмкость батареи: " << endl;
                cin >> var;
                isNumeric();
                vec5[n].SetBatteryCapacity(var);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec5.Erase(n);
                break;
            }
            case 4:
            {
                if (vec5.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec5.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec5.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec5[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec5.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec5[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                ClientNotebook* temp = vec5.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<ClientNotebook>* find = vec5.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec5[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec5.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec5[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    ClientNotebook* comp = new ClientNotebook;
                    vec5.PushBack(*comp);
                    vec5[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 5:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                ClientPC* comp = new ClientPC;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                comp->SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                cout << "Является ли ОС лицензионной?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->SetLicencedOS(true);
                else comp->SetLicencedOS(false);
                vec6.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название компьютеру: " << endl;
                cin.get();
                getline(cin, tmp);
                vec6[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec6[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec6[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec6[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec6[n].SetOS((char*)tmp.c_str());
                cout << "Изменить имя пользователя: " << endl;
                getline(cin, tmp);
                vec6[n].SetUsername((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec6[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec6[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec6[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec6[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec6[n].SetPerformanceScore(var);
                cout << "Является ли ОС лицензионной?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1)  vec6[n].SetLicencedOS(true);
                else vec6[n].SetLicencedOS(false);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec6.Erase(n);
                break;
            }
            case 4:
            {
                if (vec6.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec6.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec6.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec6[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec6.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec6[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                ClientPC* temp = vec6.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<ClientPC>* find = vec6.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec6[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec6.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec6[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    ClientPC* comp = new ClientPC;
                    vec6.PushBack(*comp);
                    vec6[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 6:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                Server* comp = new Server;
                cout << "Задать название серверу: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                comp->SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                comp->SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                comp->SetOS((char*)tmp.c_str());
                cout << "Изменить администратора сервера: " << endl;
                getline(cin, tmp);
                comp->SetAdmin((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                comp->SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                comp->SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPerformanceScore(var);
                vec4.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название серверу: " << endl;
                cin.get();
                getline(cin, tmp);
                vec4[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec4[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить модель процессора: " << endl;
                getline(cin, tmp);
                vec4[n].SetModelCPU((char*)tmp.c_str());
                cout << "Изменить модель материнской платы: " << endl;
                getline(cin, tmp);
                vec4[n].SetMotherBoardModel((char*)tmp.c_str());
                cout << "Изменить операционную систему: " << endl;
                getline(cin, tmp);
                vec4[n].SetOS((char*)tmp.c_str());
                cout << "Изменить администратора сервера: " << endl;
                getline(cin, tmp);
                vec4[n].SetAdmin((char*)tmp.c_str());
                cout << "Изменить количество жёстких дисков: " << endl;
                cin >> col;
                isNumeric();
                vec4[n].SetHardDriveCount(col);
                cout << "Изменить количество оперативной памяти (Гб): " << endl;
                cin >> col;
                isNumeric();
                vec4[n].SetRAM(col);
                cout << "Изменить мощность блока питания: " << endl;
                cin >> col;
                isNumeric();
                vec4[n].SetPowerSupplyCapacity(col);
                cout << "Изменить цену: " << endl;
                cin >> var;
                isNumeric();
                vec4[n].SetPrice(var);
                cout << "Изменить оценку производительности: " << endl;
                cin >> var;
                isNumeric();
                vec4[n].SetPerformanceScore(var);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec4.Erase(n);
                break;
            }
            case 4:
            {
                if (vec4.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cout << "2. По производительности" << endl;
                cin >> n;
                if (n == 1) {
                    vec4.ComparableSort(CompareByPrice);
                }
                else if (n == 2) {
                    vec4.ComparableSort(CompareByPerformance);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec4[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec4.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec4[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                Server* temp = vec4.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<Server>* find = vec4.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec4[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec4.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec4[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    Server* comp = new Server;
                    vec4.PushBack(*comp);
                    vec4[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 7:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                NetworkDevice* comp = new NetworkDevice;
                cout << "Задать название устройству: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить цену устройства: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                comp->SetConnectedDeviceCount(col);
                vec7.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название устройству: " << endl;
                cin.get();
                getline(cin, tmp);
                vec7[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec7[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить цену устройства: " << endl;
                cin >> var;
                isNumeric();
                vec7[n].SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                vec7[n].SetConnectedDeviceCount(col);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec7.Erase(n);
                break;
            }
            case 4:
            {
                if (vec7.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cin >> n;
                if (n == 1) {
                    vec7.ComparableSort(CompareByPrice);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec7[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec7.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec7[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                NetworkDevice* temp = vec7.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<NetworkDevice>* find = vec7.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec7[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec7.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec7[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    NetworkDevice* comp = new NetworkDevice;
                    vec7.PushBack(*comp);
                    vec7[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 8:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                NetworkAdapter* comp = new NetworkAdapter;
                cout << "Задать название устройству: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить тип устройства: " << endl;
                getline(cin, tmp);
                comp->SetType((char*)tmp.c_str());
                cout << "Изменить Wi-Fi протокол: " << endl;
                getline(cin, tmp);
                comp->SetWiFiProtocol((char*)tmp.c_str());
                cout << "Изменить интерфейс подключения: " << endl;
                getline(cin, tmp);
                comp->SetIntefaceConnect((char*)tmp.c_str());
                cout << "Изменить Mac-адрес: " << endl;
                getline(cin, tmp);
                comp->SetMACAdress((char*)tmp.c_str());
                cout << "Изменить цену устройства: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                comp->SetConnectedDeviceCount(col);
                cout << "Изменить скорость устройства: " << endl;
                cin >> var;
                isNumeric();
                comp->SetSpeed(var);
                cout << "Изменить количество антенн: " << endl;
                cin >> col;
                isNumeric();
                comp->SetCountAntennas(col);
                cout << "Изменить сетевое медиа: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->ChangeNetworkMedia(true);
                else comp->ChangeNetworkMedia(false);
                vec8.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название устройству: " << endl;
                cin.get();
                getline(cin, tmp);
                vec8[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec8[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить тип устройства: " << endl;
                getline(cin, tmp);
                vec8[n].SetType((char*)tmp.c_str());
                cout << "Изменить Wi-Fi протокол: " << endl;
                getline(cin, tmp);
                vec8[n].SetWiFiProtocol((char*)tmp.c_str());
                cout << "Изменить интерфейс подключения: " << endl;
                getline(cin, tmp);
                vec8[n].SetIntefaceConnect((char*)tmp.c_str());
                cout << "Изменить Mac-адрес: " << endl;
                getline(cin, tmp);
                vec8[n].SetMACAdress((char*)tmp.c_str());
                cout << "Изменить цену устройства: " << endl;
                cin >> var;
                isNumeric();
                vec8[n].SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                vec8[n].SetConnectedDeviceCount(col);
                cout << "Изменить скорость устройства: " << endl;
                cin >> var;
                isNumeric();
                vec8[n].SetSpeed(var);
                cout << "Изменить количество антенн: " << endl;
                cin >> col;
                isNumeric();
                vec8[n].SetCountAntennas(col);
                cout << "Изменить сетевое медиа: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) vec8[n].ChangeNetworkMedia(true);
                else vec8[n].ChangeNetworkMedia(false);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec8.Erase(n);
                break;
            }
            case 4:
            {
                if (vec8.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cin >> n;
                if (n == 1) {
                    vec8.ComparableSort(CompareByPrice);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec8[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec8.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec8[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                NetworkAdapter* temp = vec8.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<NetworkAdapter>* find = vec8.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec8[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec8.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec8[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    NetworkAdapter* comp = new NetworkAdapter;
                    vec8.PushBack(*comp);
                    vec8[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        case 9:
            cin >> choise2;
            switch (choise2)
            {
            case 1:
            {
                NetworkPrinter* comp = new NetworkPrinter;
                cout << "Задать название принтеру: " << endl;
                cin.get();
                getline(cin, tmp);
                comp->SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                comp->SetManufacturer((char*)tmp.c_str());
                cout << "Изменить тип принтера: " << endl;
                getline(cin, tmp);
                comp->SetType((char*)tmp.c_str());
                cout << "Изменить максимальное разрешение печати: " << endl;
                getline(cin, tmp);
                comp->SetMaxResolution((char*)tmp.c_str());
                cout << "Изменить максимальный размер листа: " << endl;
                getline(cin, tmp);
                comp->SetMaxPaperSize((char*)tmp.c_str());
                cout << "Какой Windows поддерживает: " << endl;
                getline(cin, tmp);
                comp->SetWindowsSupport((char*)tmp.c_str());
                cout << "Изменить цвет принтера: " << endl;
                getline(cin, tmp);
                comp->SetColor((char*)tmp.c_str());
                cout << "Изменить цену принтера: " << endl;
                cin >> var;
                isNumeric();
                comp->SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                comp->SetConnectedDeviceCount(col);
                cout << "Изменить скорость печати: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPrintSpeed(col);
                cout << "Изменить вместимость листов: " << endl;
                cin >> col;
                isNumeric();
                comp->SetPaperCapacity(col);
                cout << "Цветной принтер или нет: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->SetColorType(true);
                else comp->SetColorType(false);
                cout << "Есть ли поддержка Wi-Fi: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->SetWiFiSupport(true);
                else comp->SetWiFiSupport(false);
                cout << "Есть ли Bluetooth модуль: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) comp->SetBlueToothModule(true);
                else comp->SetBlueToothModule(false);
                vec9.PushBack(*comp);
                break;
            }
            case 2:
            {
                cout << "Введите номер объекта:" << endl;
                cin >> n;
                cout << "Задать название принтеру: " << endl;
                cin.get();
                getline(cin, tmp);
                vec9[n].SetName((char*)tmp.c_str());
                cout << "Изменить производителя: " << endl;
                getline(cin, tmp);
                vec9[n].SetManufacturer((char*)tmp.c_str());
                cout << "Изменить тип принтера: " << endl;
                getline(cin, tmp);
                vec9[n].SetType((char*)tmp.c_str());
                cout << "Изменить максимальное разрешение печати: " << endl;
                getline(cin, tmp);
                vec9[n].SetMaxResolution((char*)tmp.c_str());
                cout << "Изменить максимальный размер листа: " << endl;
                getline(cin, tmp);
                vec9[n].SetMaxPaperSize((char*)tmp.c_str());
                cout << "Какой Windows поддерживает: " << endl;
                getline(cin, tmp);
                vec9[n].SetWindowsSupport((char*)tmp.c_str());
                cout << "Изменить цвет принтера: " << endl;
                getline(cin, tmp);
                vec9[n].SetColor((char*)tmp.c_str());
                cout << "Изменить цену принтера: " << endl;
                cin >> var;
                isNumeric();
                vec9[n].SetPrice(var);
                cout << "Изменить количество подключенных устройств: " << endl;
                cin >> col;
                isNumeric();
                vec9[n].SetConnectedDeviceCount(col);
                cout << "Изменить скорость печати: " << endl;
                cin >> col;
                isNumeric();
                vec9[n].SetPrintSpeed(col);
                cout << "Изменить вместимость листов: " << endl;
                cin >> col;
                isNumeric();
                vec9[n].SetPaperCapacity(col);
                cout << "Цветной принтер или нет: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) vec9[n].SetColorType(true);
                else vec9[n].SetColorType(false);
                cout << "Есть ли поддержка Wi-Fi: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) vec9[n].SetWiFiSupport(true);
                else vec9[n].SetWiFiSupport(false);
                cout << "Есть ли Bluetooth модуль: " << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> col;
                isNumeric();
                if (col == 1) vec9[n].SetBlueToothModule(true);
                else vec9[n].SetBlueToothModule(false);
                break;
            }
            case 3:
            {
                cout << "Выберите номер объекта, который хотите удалить:" << endl;
                cin >> n;
                vec9.Erase(n);
                break;
            }
            case 4:
            {
                if (vec9.Length() == 0) throw Exception("Нечего сортировать!");
                cout << "По какому параметру сортировать?" << endl;
                cout << "1. По цене" << endl;
                cin >> n;
                if (n == 1) {
                    vec9.ComparableSort(CompareByPrice);
                }
                break;
            }
            case 5:
            {
                cout << "Введите номер объекта: " << endl;
                cin >> n;
                vec9[n].PrintAllInformation();
                break;
            }
            case 6:
            {
                for (int i = 0; i < vec9.Length(); i++) {
                    cout << "№" << i + 1 << ": " << vec9[i].GetName() << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Введите стоимость объекта, который хотите найти:" << endl;
                cin >> var;
                NetworkDevice* temp = vec9.Search(var, FinderByPrice);
                if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
                else temp->PrintAllInformation();
                break;
            }
            case 8:
            {
                double min, max;
                cout << "Введите минимальную стоимость компьютеров: " << endl;
                cin >> min;
                cout << "Введите максимальную стоимость компьютеров: " << endl;
                cin >> max;
                Vector<NetworkPrinter>* find = vec9.Search(min, max, FinderAllByPrice);
                cout << "Ваши найденные элементы: " << endl;
                for (int i = 0; i < find->Length(); i++) {
                    cout << i + 1 << (*find)[i].GetName() << endl;
                }
                delete find;
                break;
            }
            case 9:
            {
                cout << "Укажите номер компьютера, который хотите записать в файл" << endl;
                cin >> n;
                cout << "Укажите путь для сохранения файла" << endl;
                cin >> tmp;
                vec9[n].WriteToFile((char*)tmp.c_str());
                break;
            }
            case 10:
            {
                cout << "Укажите путь до считываемого файла" << endl;
                cin >> tmp;
                if (vec9.Length() > 0) {
                    cout << "Укажите номер компьютера, в который хотите записать информацию" << endl;
                    cin >> n;
                    vec9[n].ReadFromFile((char*)tmp.c_str());
                }
                else {
                    NetworkPrinter* comp = new NetworkPrinter;
                    vec9.PushBack(*comp);
                    vec9[0].ReadFromFile((char*)tmp.c_str());
                }
                break;
            }
            default:
            {
                system("pause");
                return 0;
            }
            }
            break;
        default:
            system("pause");
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
