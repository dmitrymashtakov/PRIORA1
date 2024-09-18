#include "cipher.h"
cipher::cipher(int key) { stolb = key; }
wstring cipher::encrypt(wstring text)
{
    int s = text.size();
    int str = (s + stolb - 1) / stolb;
    for(int i = 0; i < s; ++i) {
        int a = i / stolb;
        int b = i % stolb;
        table[a][b] = text[i];
    }
    wstring res;
    for(int i = stolb - 1; i >= 0; --i) {
        for(int j = 0; j < str; ++j) {
            if(table[j].count(i) > 0) {
                res += table[j][i];
            }
        }
    }
    return res;
}
wstring cipher::decrypt(wstring text)
{
    int s = text.size();
    int str = (s + stolb - 1) / stolb;
    int index = 0;
    for(int i = stolb - 1; i >= 0; --i) {
        for(int j = 0; j < str; ++j) {
            if(table[j].count(i) > 0) {
                table[j][i] = text[index++];
            }
        }
    }
    wstring res;
    for(int i = 0; i < s; ++i) {
        int a = i / stolb;
        int b = i % stolb;
        res += table[a][b];
    }
    return res;
}