// main.cpp
// Лабораторна робота №9 — Робота з рядками на C++
// Варіант: Лєсніков Артем Олександрович, група 319
//   Завдання 1 (Табл.1, вар.22): void swap(string& str)
//   Завдання 2 (Табл.2, String33): видалити першу підстроку S0 з рядка S

#include <iostream>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif
#include "task1.h"
#include "task2.h"
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "  ЛР №9 — Робота з рядками на C++\n";
        cout << "  Лєсніков Артем Олександрович, гр.319\n";
        cout << "========================================\n";
        cout << "1. Завдання 1: swap(string& str)  (вар.22)\n";
        cout << "2. Завдання 2: String33 — видалити першу підстроку S0\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введіть ціле число!\n";
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 0: cout << "До побачення!\n"; break;
            default: cout << "Невірний вибір. Введіть 0-2.\n";
        }

    } while (choice != 0);

    return 0;
}
