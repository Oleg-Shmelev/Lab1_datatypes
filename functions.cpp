#include "functions.h"

#include <iostream>
using namespace std;

void sizeofdatatypes() {
    // Функция которая выводит размеры разных типов данных
    cout << "Размер bool: " << sizeof(bool) << " байт" << endl;
    cout << "Размер char: " << sizeof(char) << " байт" << endl;
    cout << "Размер short int: " << sizeof(short int) << " байта" << endl;
    cout << "Размер int: " << sizeof(int) << " байта" << endl;
    cout << "Размер long int: " << sizeof(long int) << " байт" << endl;
    cout << "Размер float: " << sizeof(float) << " байта" << endl;
    cout << "Размер double: " << sizeof(double) << " байт" << endl;
    cout << "Размер long double: " << sizeof(long double) << " байт" << endl;
}

void binofint(int num, int width) {
    // Функция которая выводит двоичное представление целого числа
    unsigned unsigned_num = static_cast<unsigned>(num);
    for (int i = width - 1; i >= 0; --i) {
        if (i == width - 1) cout << "sign:";
        cout << (((unsigned_num >> i) & 1u) ? '1' : '0');
        if (i == width - 1) cout << ' ';
        if ((width - 1 - i) % 8 == 7) cout << ' ';
    }
    cout << endl;
}

void binoffloat(float fnum) {
    // Функция которая выводит двоичное представление дробного числа (float)
    uint32_t b;
    memcpy(&b, &fnum, sizeof(b));

    cout << "sign:" << (b >> 31) << " exp:";
    for (int i = 30; i >= 23; --i) cout << ((b >> i) & 1u);
    cout << " mant:";
    for (int i = 22; i >= 0; --i) cout << ((b >> i) & 1u);
    cout << endl;
}

void binofdouble(double dnum) {
    // Функция которая выводит двоичное представление дробного числа (double)
    uint64_t b;
    memcpy(&b, &dnum, sizeof(b));

    cout << "sign:" << (b >> 63) << " exp:";
    for (int i = 62; i >= 52; --i) cout << ((b >> i) & 1u);
    cout << " mant:";
    for (int i = 51; i >= 0; --i) cout << ((b >> i) & 1u);
    cout << endl;
}

float bitinvertion(float f, int poz, const string &com) {
    // Изменение бита у float
    uint32_t b;
    memcpy(&b, &f, sizeof(b));
    b = bitinvertion(b, poz, com);
    memcpy(&f, &b, sizeof(f));
    return f;
}

double bitinvertion(double d, int poz, const string &com) {
    // Изменение бита у double
    uint64_t b;
    memcpy(&b, &d, sizeof(b));
    b = bitinvertion(b, poz, com);
    memcpy(&d, &b, sizeof(d));
    return d;
}
