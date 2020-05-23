#pragma once
#include <algorithm>
#include "Computer.h"

template<class T>
class Vector {
public:
    Vector();
    Vector(int size);
    Vector(const Vector<T>& other);
    void Insert(int n, T& element);
    void PushBack(T& element);
    void Erase(int n);
    T& operator[](int n);
    int Length() const;
    void Clear();
    void Sort();
    void ComparableSort(bool(*cmp)(const T& a,const T& b));
    template<class C>
    T* Search(C value, bool(*finder)(C value, const T& comp));
    template<class C>
    Vector<T>* Search(C min, C max, bool(*finder)(C min, C max, const T& comp));
    ~Vector();
private:
    int Size;
    T* Mas;
};
template<class T>
Vector<T>::Vector() {
    Size = 0;
    Mas = new T[Size];
}
template<class T>
Vector<T>::Vector(int size) {
    Size = size;
    Mas = new T[Size];
}
template<class T>
Vector<T>::Vector(const Vector<T>& other) {
    Size = other.Size;
    Mas = new T[Size];
}
template<class T>
void Vector<T>::Insert(int n, T& element) {
    if (n < 0 || n > Size) throw Exception("Указан неверный элемент для вставки!");
    T* temp = new T[Size + 1];
    for (int i = 0; i < n; i++) {
        temp[i] = Mas[i];
    }
    temp[n] = element;
    for (int i = n + 1; i < Size + 1; i++) {
        temp[i] = Mas[i - 1];
    }
    delete[] Mas;
    Mas = temp;
    Size++;
}
template<class T>
void Vector<T>::PushBack(T& element) {
    T* temp = new T[Size + 1];
    for (int i = 0; i < Size; i++) {
        temp[i] = Mas[i];
    }
    temp[Size] = element;
    delete[] Mas;
    Mas = temp;
    Size++;
}
template<class T>
void Vector<T>::Erase(int n) {
    if (n < 0 || n > Size - 1) throw Exception("Вы попытались стереть несуществующий элемент!");
    T* temp = new T[Size - 1];
    for (int i = 0; i < n; i++) {
        temp[i] = Mas[i];
    }
    for (int i = n; i < Size - 1; i++) {
        temp[i] = Mas[i + 1];
    }
    delete[] Mas;
    Mas = new T[Size - 1];
    Mas = temp;
    Size--;
}
template<class T>
T& Vector<T>::operator[](int n) {
    if (n < 0 || n > Size - 1) throw Exception("Произошёл выход за пределы массива!");
    return Mas[n];
}
template<class T>
int Vector<T>::Length() const{
    return Size;
}
template<class T>
void Vector<T>::Clear() {
    for (int i = 0; i < Size; i++) {
        Mas[i] = 0;
    }
}
template<class T>
void Vector<T>::Sort() {
    if (Size == 0) throw Exception("Нечего сортировать!");
    int step = Size / 2;
    while (step > 0) {
        for (int i = 0; i < Size - step; i++) {
            int j = i;
            while (j >= 0 && Mas[j] > Mas[j + step]) {
                std::swap(Mas[j], Mas[j + step]);
                j -= step;
            }
        }
        step /= 2;
    }
}
template<class T>
void Vector<T>::ComparableSort(bool(*cmp)(const T& a,const T& b)) {
    if (Size == 0) throw Exception("Нечего сортировать!");
    int step = Size / 2;
    while (step > 0) {
        for (int i = 0; i < Size - step; i++) {
            int j = i;
            while (j >= 0 && cmp(Mas[j], Mas[j+step])) {
                std::swap(Mas[j], Mas[j + step]);
                j -= step;
            }
        }
        step /= 2;
    }
}
template <class T> template<class C>
T* Vector<T>::Search(C value, bool(*finder)(C value, const T& comp)) {
    for (int i = 0; i < Size; i++) {
        if (FinderByPrice(value, Mas[i])) return &Mas[i];
    }
    return nullptr;
}
template <class T> template<class C>
Vector<T>* Vector<T>::Search(C min, C max, bool(*finder)(C min, C max, const T& comp)) {
    Vector<T>* temporary = new Vector<T>();
    for (int i = 0; i < Size; i++) {
        if (FinderAllByPrice(min,max, Mas[i])) temporary->PushBack(Mas[i]);
    }
    if (temporary->Size == 0) return nullptr;
    return temporary;
}
template<class T>
Vector<T>::~Vector() {
    delete[] Mas;
}