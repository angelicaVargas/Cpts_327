#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Decrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < plaintext.length(); ++i) {
        char currentChar = plaintext[i];

        if (islower(currentChar)) {
            char keyChar = tolower(key[j % keyLength]);
            char shift = currentChar - 'a';
            char decryptedChar = 'a' + (shift - (keyChar - 'a') + 26) % 26;

            ciphertext += decryptedChar;
            ++j;
        }
        else {
            ciphertext += currentChar;
            continue;
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
    string ciphertext = Decrypt(plaintext, key);

    // Display the encrypted text
    cout << "Decrypted Text: " << ciphertext << endl;

    return 0;
}