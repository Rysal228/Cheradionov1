﻿
#include <iostream>
#include <clocale>
using namespace std;
<<<<<<< HEAD
double my_pow(double a, int b);

=======
double BinaryPower(double b, unsigned long long e);
double FastPowerDividing(double b, double e);
>>>>>>> feature_fast
int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    int b;
    cout << "Введите дробное число" << endl;
    cin >> a;
    cout << "Введи степень, в которую будете возводить число " << endl;
    cin >> b;
    cout << my_pow(a, b); << endl;
    cout << BinaryPower(a, b) << endl;
    cout << FastPowerDividing(a, b) << endl;
}

double my_pow(double a, int b)
{
    double result = 1;
    int loop_ends;
    if (b < 0)
        loop_ends = -1 * b;
    else
        loop_ends = b;
    for (int i = 0; i < loop_ends; i++)
    {
        result *= a;
    }
    if (b < 0)
        result = 1 / result;
    return result;
}

double OldApproximatePower(double b, double e) {
    union {
        double d;
        long long i;
    } u = { b };
    u.i = (long long)(4606853616395542500L + e * (u.i - 4606853616395542500L));
    return u.d;
}
double BinaryPower(double b, unsigned long long e) {
    double v = 1.0;
    while (e != 0) {
        if ((e & 1) != 0) {
            v *= b;
        }
        b *= b;
        e >>= 1;
    }
    return v;
}
double FastPowerDividing(double b, double e) {
    if (b == 1.0 || e == 0.0) {
        return 1.0;
    }

    double eAbs = fabs(e);
    double el = ceil(eAbs);
    double basePart = OldApproximatePower(b, eAbs / el);
    double result = BinaryPower(basePart, (unsigned long long)el);

    if (e < 0.0) {
        return 1.0 / result;
    }
    return result;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
