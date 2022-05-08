#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string t, int offset)
{
    for (int i = 0; i < t.length(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z' || t[i] >= 'a' && t[i] <= 'z') {
            int temp = t[i] - 'a';
            if (temp >= 0) {
                temp = (temp + offset) < 0 ? (26 + temp) : temp;
                temp += offset;
                temp %= 26;
                t[i] = (char) ('a' + temp);
            } else {
                temp = t[i] - 'A';
                temp = (temp + offset) < 0 ? (26 + temp) : temp;
                temp += offset;
                temp %= 26;
                t[i] = (char) ('A' + temp);
            }
        }
    }
    return t;
}

string decrypt_caesar(string t, int offset)
{
    for (int i = 0; i < t.length(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z' || t[i] >= 'a' && t[i] <= 'z') {
            int temp = t[i] - 'a';
            if (temp >= 0) {
                temp = (temp - offset) < 0 ? (26 + temp) : temp;
                temp -= offset;
                temp %= 26;
                t[i] = (char) ('a' + temp);
            } else {
                temp = t[i] - 'A';
                temp = (temp - offset) < 0 ? (26 + temp) : temp;
                temp -= offset;
                temp %= 26;
                t[i] = (char) ('A' + temp);
            }
        }
    }
    return t;
}

int main() {
    string text;
    int shift;
    cout << "Enter text to encrypt: " << endl;
    getline(cin, text);
    cout << "Enter shift: " << endl;
    cin >> shift;
    string encryptText = encrypt_caesar(text, shift);
    cout << "Result: " << endl;
    cout << encryptText << endl;
    string decryptText = decrypt_caesar(encryptText, shift);
    //string decryptText = encrypt_caesar(encryptText, -shift);
    cout << "Decrypt: " << endl;
    cout << decryptText << endl;
    return 0;
}
