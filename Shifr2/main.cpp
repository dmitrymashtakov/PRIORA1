#include "cipher.h"
#include <iostream>
using namespace std;
int main()
{
    int key;
    string text;
    unsigned op;
    cout << "Vvedi key: ";
    cin >> key;
    if(key <= 0) {
    cout << "Key ploxoi" << endl;
    } else {
    cout << "Key accepted" << endl;
    cipher c(key);
    do {
        cout << "Vvedi metod (1 - encrypt, 2 - decrypt, 0 - exit): ";
        cin >> op;
        if(op > 2) {
            cout << "Nekorrektno" << endl;
        } else if(op > 0) {
            cout << "Vvedi text (bez probelov): ";
            cin >> text;
                if(op == 1) {
                    cout << "Encrypted text: " << c.encrypt(text) << endl;
                } else {
                    cout << "Decrypted text: " << c.decrypt(text) << endl;
                }
        }
    } while(op != 0);
    }
}