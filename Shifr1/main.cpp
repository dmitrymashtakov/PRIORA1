#include "modAlphaCipher.h"
#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"Ключ=" << key << endl;
    wcout << Text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    if(Text == decryptedText)
        wcout << L"ОК\n";
    else
	 	wcout << L"Плохо\n";
}
int main(int argc, char** argv)
{
	std::locale loc("ru_RU.UTF-8");
	std::locale::global(loc);
    check(L"ПРИВЕТ", L"СИМПЛ");
    check(L"ИВАНШУРМАНОВ", L"ЕКЗАМПЛЕ");
    check(L"ЯЗЫКИПРОГРАММИРОВАНИЯ", L"АБВГ");
    return 0;
}