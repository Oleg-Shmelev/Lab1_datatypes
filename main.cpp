#include <iostream>
#include <limits>
#include "functions.h"
using namespace std;

int main() {
    cout << "Размеры типов данных:" << endl;
    sizeofdatatypes();

    cout << endl << "Битовое представление целых чисел:" << endl;
    int ints[] = {42, -42, 0};
    for (int v: ints) {
        cout << v << ": ";
        binofint(v);
    }

    cout << endl << "Битовое представление чисел типа float:" << endl;
    float floats[] = {0.15625f, -118.625f, 3.14f, -2.5f, 0.1f, 0.0f, 1e-40f, numeric_limits<float>::infinity()};
    for (float v: floats) {
        cout << v << ": ";
        binoffloat(v);
    }

    cout << endl << "Битовое представление чисел типа double:" << endl;
    double doubles[] = {0.15625, -118.625, 3.14, -2.5, 0.1, 0.0, 1e-310, numeric_limits<double>::infinity()};
    for (double v: doubles) {
        cout << v << ": ";
        binofdouble(v);
    }

    cout << endl << "Изменение бита:" << endl;
    uint32_t u1 = bitinvertion(uint32_t(5), 1, "set");
    cout << "5, set бит 1:   ";
    binofint(static_cast<int>(u1));

    uint32_t u2 = bitinvertion(static_cast<uint32_t>(-1), 31, "res");
    cout << "-1, res бит 31: ";
    binofint(static_cast<int>(u2));

    uint32_t u3 = bitinvertion(uint32_t(42), 0, "inv");
    cout << "42, inv бит 0:  ";
    binofint(static_cast<int>(u3));

    float f1 = 1.5f;
    float f2 = bitinvertion(f1, 31, "inv");
    cout << f1 << ", inv бит 31 -> " << f2 << endl;
    binoffloat(f1);
    binoffloat(f2);

    float f3 = 1.0f;
    float f4 = bitinvertion(f3, 30, "set");
    cout << f3 << ", set бит 30 -> " << f4 << endl;
    binoffloat(f3);
    binoffloat(f4);

    double d1 = 2.0;
    double d2 = bitinvertion(d1, 63, "inv"); // 2.0 -> -2.0
    cout << d1 << ", inv бит 63 -> " << d2 << endl;
    binofdouble(d1);
    binofdouble(d2);

    cout << endl << "Умножение на 2 через битовый сдвиг:" << endl;
    int mults[] = {21, -21, 0};
    for (int v: mults) {
        cout << v << " * 2 = " << mult2(v) << endl;
    }

    return 0;
}
