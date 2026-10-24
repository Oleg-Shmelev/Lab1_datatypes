#pragma once

#include <string>

void sizeofdatatypes(); // Размеры типов данных
void binofint(int num, int width = 32); // Двоичное представление целого числа
void binoffloat(float fnum); // Двоичное представление float (знак / порядок / мантисса)
void binofdouble(double dnum); // Двоичное представление double (знак / порядок / мантисса)

// Изменение бита у целых типов:
template<typename T>
T bitinvertion(T num, int poz, const std::string &com) {
    T mask = static_cast<T>(T(1) << poz);

    if (com == "set") return num | mask;
    if (com == "res") return num & ~mask;
    if (com == "inv") return num ^ mask;
    return num;
}

// Версии для вещественных чисел
float bitinvertion(float f, int poz, const std::string &com);

double bitinvertion(double d, int poz, const std::string &com);

// Умножение на 2 через битовый сдвиг
template<typename T>
T mult2(T num) {
    return num << 1;
}
