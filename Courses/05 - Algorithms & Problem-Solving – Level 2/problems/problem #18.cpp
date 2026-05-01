
#include <iostream>
#include <string>

using namespace std;

string ReadPassword(string message) {
    string pass = "";
    cout << message << endl;
    getline(cin,pass);

    return pass;

}
string encrypt(string Text, short EncryptionKey) {
   

    for (short i = 0;i < Text.length() ; i++) {
        Text[i] = char(int(Text[i]) + EncryptionKey);

    }
    return Text;
}

string decrypt(string Text, short EncryptionKey) {
    

    for (short i = 0;i < Text.length(); i++) {
        Text[i] = char(int(Text[i]) - EncryptionKey);

    }
    return Text;
}


int main()
{
    short EncryptionKey = 2;
    string name = ReadPassword("please enter a your name to encrypt/decrypt: ");
    string TextAfterEncryption = encrypt(name, EncryptionKey);
    string TextAfterDecryption = decrypt(TextAfterEncryption, EncryptionKey);

    cout << "Text Before encryption: " << name <<endl;
    
    cout << "Text After encryption: " << TextAfterEncryption << endl;

    cout << "Text After Decryption: " << TextAfterDecryption << endl;


}