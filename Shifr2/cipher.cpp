#include "cipher.h"
cipher::cipher(int key) { 
    stolb = key; 
    }
string cipher::encrypt(string text)
{
    int s = text.length();
    int str = ceil(double(s) / stolb);
    char table[str][stolb] = {' '};
    string res;
    int index = 0;
    for(int a = 0; a < str; ++a) {
        for(int b = 0; b < stolb; ++b) {
            table[a][b] = text[index];
            index++;
        }
    }
    for(int i = stolb - 1; i >= 0; --i) {
        for(int j = 0; j < str; ++j) {
            if(table[i][j] != ' ') {
                res += table[j][i];
            }
        }
    }
    return res;
}
string cipher::decrypt(string text)
{
    int s = text.length();
    int p = s;
    string res;
    int str = ceil(double(s) / stolb);
    char table[str][stolb];
    for (int x = 0; x < s; x++) {
        if (p%stolb != 0) {
        p++;
    } else {
        break;
    }
    }
    int n = p-s;
    int h = str - 1;
    int z = 0;
    for (int j = stolb - 1; j >= 0; --j) {
            if (z < n) {
            table[h][j] = ' ';
            z++;
            } else {
                break;
            }
    }
    int index = 0;
    for (int i = stolb - 1; i >= 0; --i) {
        for (int j = 0; j < str; ++j) {
            if (index < s and table[j][i] != ' ') {
                table[j][i] = text[index];
                index++;
            }
            }
        }
    for (int a = 0; a < str; ++a) {
        for (int b = 0; b < stolb; ++b) {
            if (table[a][b] != ' ') {
                res += table[a][b];
            }
        }
    }
    return res;
}