#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <map>
using namespace std;
class cipher {
private:
    int stolb;
public:
    cipher(int key);
    cipher() = delete;
    wstring encrypt(wstring text);
    wstring decrypt(wstring text);
};