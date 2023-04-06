#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
    string str1;
    
    cin >> str1;
    
    for(int i=0; i<str1.size(); i++) {
        if(isupper(str1[i]))
            str1[i] = tolower(str1[i]);
        else if(islower(str1[i]))
            str1[i] = toupper(str1[i]);
    }
    
    cout << str1;
    
    return 0;
}