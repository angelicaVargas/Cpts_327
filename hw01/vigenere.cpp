#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// decrypts input plaintext
string decrypt(const string& plaintext, const string& key) {
    string decrypted_text = "";
    size_t key_length = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char current_char = plaintext[i];
        char key_char = key[i % key_length];

        if (isalpha(current_char)) {
            char decrypted_char = ((current_char - key_char + 26) % 26) + 'a';
            decrypted_text += decrypted_char;
        } else {
            decrypted_text += current_char;
        }
    }

    return decrypted_text;
}

// goes through all of the alphabet to find key
void brute_force_attack(const string& plaintext, size_t key_length) {
    string current_key(key_length, 'A'); 

    do {
        // key contains only capitalized letters
        if (all_of(current_key.begin(), current_key.end(), ::isupper)) {
            string decrypted_text = decrypt(plaintext, current_key);
            cout << "Key: " << current_key << endl;
            cout << "Decrypted Text: " << decrypted_text << endl;
        }

        // increments key to next permutation
        for (int i = key_length - 1; i >= 0; --i) {
            if (current_key[i] < 'Z') {
                current_key[i]++;
                break;
            } else {
                current_key[i] = 'A';
            }
        }
    } while (current_key != string(key_length, 'A'));  // stops once key is all As
}

int main() {
    string plaintext = "ulzx ooakycdmtvdhd hutu pletetf pho qmrztld ea ekpgtymtvdhd zr tbecnd xixt zzzp snuyej mnq uicpeten, qdf boqrudee scph l hudr plclk os iiatos ncx deklrh. Cy lpdviczy fo cdxnletf elzogcrs vj heu spwfwfy ncx demfs, ibp amgr xhnwgdrh u dpxepiczy af cgircmmf elzogcrs umzgt gwy fyuvrgmtek fedg lwgmax uyo oozboytfy ztgmpd";
    size_t key_length = 7;

    brute_force_attack(plaintext, key_length);

    return 0;
}
