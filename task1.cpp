#include "task1.h"
#include <iostream>
#include <string>
using namespace std;

// Власна реалізація void swap(string& str) для масивів символів.
// Реалізована через тимчасовий буфер без використання функцій обробки рядків.
// Передумова: обидва буфери достатньо великі, щоб вмістити вміст один одного.
void mySwap(char* s1, char* s2) {
    // Знаходимо довжини рядків вручну
    int len1 = 0, len2 = 0;
    while (s1[len1]) len1++;
    while (s2[len2]) len2++;

    // Копіюємо s1 у тимчасовий буфер
    const int TEMP_BUF = 512;
    char temp[TEMP_BUF];
    for (int i = 0; i <= len1; i++)
        temp[i] = s1[i];

    // Копіюємо s2 у s1
    for (int i = 0; i <= len2; i++)
        s1[i] = s2[i];

    // Копіюємо тимчасовий буфер у s2
    for (int i = 0; i <= len1; i++)
        s2[i] = temp[i];
}

void task1() {
    const int BUF = 512;
    char cstr1[BUF], cstr2[BUF];

    cout << "\n=== Завдання 1: void swap(string& str) ===\n";
    cout << "Введіть перший рядок: ";
    cin.ignore();
    cin.getline(cstr1, BUF);

    cout << "Введіть другий рядок: ";
    cin.getline(cstr2, BUF);

    string str1(cstr1), str2(cstr2);

    cout << "\nДо обміну:\n";
    cout << "  cstr1 = \"" << cstr1 << "\"\n";
    cout << "  cstr2 = \"" << cstr2 << "\"\n";
    cout << "  str1  = \"" << str1  << "\"\n";
    cout << "  str2  = \"" << str2  << "\"\n";

    // Власна реалізація
    mySwap(cstr1, cstr2);
    // Метод std::string
    str1.swap(str2);

    cout << "\nПісля mySwap(cstr1, cstr2):\n";
    cout << "  cstr1 = \"" << cstr1 << "\"\n";
    cout << "  cstr2 = \"" << cstr2 << "\"\n";

    cout << "\nПісля str1.swap(str2):\n";
    cout << "  str1  = \"" << str1 << "\"\n";
    cout << "  str2  = \"" << str2 << "\"\n";

    bool match = (string(cstr1) == str1) && (string(cstr2) == str2);
    cout << "\nРезультати " << (match ? "збігаються ✓" : "НЕ збігаються ✗") << "\n";
}
