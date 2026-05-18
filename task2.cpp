#include "task2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

// 2.B: перевіряє, чи містить рядок s підрядок s0
bool containsSubstr(const char* s, const char* s0) {
    int len = (int)strlen(s);
    int len0 = (int)strlen(s0);
    if (len0 == 0) return true;
    if (len0 > len) return false;
    for (int i = 0; i <= len - len0; i++) {
        bool match = true;
        for (int j = 0; j < len0; j++) {
            if (s[i + j] != s0[j]) { match = false; break; }
        }
        if (match) return true;
    }
    return false;
}

// 2.A: видаляє першу підстроку s0 з рядка s (рядок змінюється на місці)
void deleteFirstSubstr(char* s, const char* s0) {
    int len = (int)strlen(s);
    int len0 = (int)strlen(s0);
    if (len0 == 0 || len0 > len) return;
    for (int i = 0; i <= len - len0; i++) {
        bool match = true;
        for (int j = 0; j < len0; j++) {
            if (s[i + j] != s0[j]) { match = false; break; }
        }
        if (match) {
            // Зсуваємо залишок рядка вліво
            int rest = len - i - len0;
            for (int k = 0; k <= rest; k++)
                s[i + k] = s[i + len0 + k];
            return;
        }
    }
}

void task2() {
    const int BUF = 1024;
    char s0[BUF];
    string inFile, outFile;

    cout << "\n=== Завдання 2: String33 — видалити першу підстроку S0 ===\n";
    cout << "Введіть підрядок S0 для видалення: ";
    cin.ignore();
    cin.getline(s0, BUF);

    cout << "Ім'я вхідного файлу:  ";
    getline(cin, inFile);
    cout << "Ім'я вихідного файлу: ";
    getline(cin, outFile);

    ifstream fin(inFile);
    if (!fin) {
        cout << "Помилка: не вдалося відкрити файл \"" << inFile << "\"\n";
        return;
    }
    ofstream fout(outFile);
    if (!fout) {
        cout << "Помилка: не вдалося відкрити файл \"" << outFile << "\"\n";
        return;
    }

    string line;
    int lineNum = 0;
    while (getline(fin, line)) {
        lineNum++;
        char cline[BUF];
        strncpy(cline, line.c_str(), BUF - 1);
        cline[BUF - 1] = '\0';

        cout << "Рядок " << lineNum << ": \"" << cline << "\"\n";

        if (containsSubstr(cline, s0)) {
            deleteFirstSubstr(cline, s0);
            cout << "  -> \"" << cline << "\" (підрядок видалено)\n";
        } else {
            cout << "  -> (підрядок не знайдено, рядок без змін)\n";
        }

        fout << cline << "\n";
    }

    fin.close();
    fout.close();
    cout << "\nОброблено рядків: " << lineNum << "\n";
    cout << "Результат збережено у файл \"" << outFile << "\"\n";
}
