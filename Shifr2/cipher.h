#pragma once
#include <iostream>
#include <locale>
#include <map>
#include <string>
using namespace std;
class cipher
{
private:
    int stolb;
    map<int, map<int, wchar_t>> table;
public:
    cipher(int key);
    cipher() = delete;
    wstring encrypt(wstring text);
    wstring decrypt(wstring text);
};