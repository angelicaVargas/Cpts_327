#include <iostream>
#include <string>
using namespace std;
class Vig {
   public:
      string k;
   Vig(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   string encryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
   string decryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
};
int main() {
   Vig v("WELCOMESE");
   string ori ="ulzx ooakycdmtvdhd hutu pletetf pho qmrztld ea ekpgtymtvdhd zr tbecnd xixt zzzp snuyej mnq uicpeten, qdf boqrudee scph l hudr plclk os iiatos ncx deklrh. Cy lpdviczy fo cdxnletf elzogcrs vj heu spwfwfy ncx demfs, ibp amgr xhnwgdrh u dpxepiczy af cgircmmf elzogcrs umzgt gwy fyuvrgmtek fedg lwgmax uyo oozboytfy ztgmpd";
   string encrypt = v.encryption(ori);
   string decrypt = v.decryption(encrypt);
   cout << "Original Message: "<<ori<< endl;
   cout << "Encrypted Message: " << encrypt << endl;
   cout << "Decrypted Message: " << decrypt << endl;
}