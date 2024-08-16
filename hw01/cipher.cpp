#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < plaintext.length(); ++i) {
        char currentChar = plaintext[i];

        if (islower(currentChar)) {
            char keyChar = tolower(key[j % keyLength]);
            char shift = currentChar - 'a';
            char encryptedChar = 'a' + (shift + (keyChar - 'a')) % 26;

            ciphertext += encryptedChar;
            ++j;
        }
        else {
            ciphertext += currentChar;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    // Input plaintext and key
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);

    // Encrypt the plaintext using the Vigenere cipher
    string ciphertext = Encrypt(plaintext, key);

    // Display the encrypted text
    cout << "Encrypted Text: " << ciphertext << endl;

    return 0;
}