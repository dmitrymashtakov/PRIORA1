#include "cipher.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    int key;
    wstring text;
    unsigned op;
    wcout << L"Введите ключ: ";
    wcin >> key;
    if(key <= 0) {
        wcout << L"Ключ некорректен" << endl;
    } else {
        wcout << "Ключ введен" << endl;
        cipher c(key);
        do {
            wcout << L"Алгоритм готов к работе. Выберите действие (0 - выход, 1 - зашифрование, 2 - расшифрование): ";
            wcin >> op;
            if(op > 2) {
                wcout << L"Некорректное действие";
            } else if(op > 0) {
                wcout << L"Введите текст: ";
                wcin >> text;
                if(op == 1) {
                    wcout << L"Зашифрованный текст: " << c.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << c.decrypt(text) << endl;
                }
            }
        } while(op != 0);
        return 0;
    }
}
