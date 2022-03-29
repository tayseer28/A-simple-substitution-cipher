/* author: Tayseer Abdelqader Adelhameed
   Cs112
   Dr:Mohamed El-ramly



   this is a Simple Substitution  Cipher to encrypt and decrypt a text based on a keyword as a inputs from the user
*/


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;



void encryption_function()
{
    string text, key_word;
    cout << "Enter the text yo want to be ciphered: ";
    cin.ignore();
    getline(cin, text);
    cout << "keyword must be 5 unique letters\n";
    cout << "enter the key word: ";
    cin >> key_word;
    while(key_word.size() < 5 || key_word.size() > 5){

        cout << "please enter only five unique letters";
        cin >> key_word;
    }
    char alpha1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, alpha2[26];
    // append key word in alpha2
    if(key_word.size() == 5) {
        alpha2[0] = key_word[0];
        alpha2[1] = key_word[1];
        alpha2[2] = key_word[2];
        alpha2[3] = key_word[3];
        alpha2[4] = key_word[4];
        int counter = 5;
        for (char i = 'a'; i <= 'z'; i++) {
            bool flag = true; //if flag is true that means this char is not in keyword an we will append it in alpha2 and vice versa
        for(int j = 0; j < key_word.size(); j++){

            if (key_word[j] == i){
                flag = false;
                break;

            }
        }if(flag == true){
            alpha2[counter] = i;
                counter++;
        }

        }
        for(int x = 0; x < text.size(); x++){
        for(int n = 0; n < 26; n++){ // check if certain char in text equal a certain char in alpha1 to convert it to the same index equivalent in alpha2
            if(text[x] == alpha1[n]){
                text[x] = alpha2[n];
                break;
    }
            }
        }cout << text;

    }

}



void decryption_function()
{
    string text, key_word;
    cout << "Enter the text yo want to be deciphered: ";
    cin.ignore();
    getline(cin, text);
    cout << "keyword must be 5 unique letters\n";
    cout << "Enter the key word: ";
    cin >> key_word;
    while(key_word.size() < 5 || key_word.size > 5){

        cout << "please enter only five unique letters";
        cin >> key_word;
    }

    char alpha1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, alpha2[26];

    if(key_word.size() == 5) {

        alpha2[0] = key_word[0];
        alpha2[1] = key_word[1];
        alpha2[2] = key_word[2];
        alpha2[3] = key_word[3];
        alpha2[4] = key_word[4];
        int counter = 5;
        for (char i = 'a'; i <= 'z'; i++) {
            bool flag = true;
        for(int j = 0; j < key_word.size(); j++){

            if (key_word[j] == i){
                flag = false;
                break;

            }
        }if(flag == true){
            alpha2[counter] = i;
                counter++;
        }

        }
        for(int x = 0; x < text.size(); x++){
        for(int n = 0; n < 26; n++){
            if(text[x] == alpha2[n]){
                text[x] = alpha1[n];
                break;
    }
            }
        }cout << text;

    }

}






int main()
{
    cout << "1-encryption" << "\n" << "2-decryption\n";
    cout << "Enter a number based on what do you want to do: ";
    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        encryption_function();
        break;
    case 2:
        decryption_function();
        break;
    default :
        cout << "end";
    }


    return 0;
}
