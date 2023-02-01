#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    string str;
    getline(cin, str);
    
    for(int i=0; i<str.size(); i++) {
        if(isalpha(str[i])) {
            if(isupper(str[i])) {
                str[i] =  'A' + ((str[i] - 'A' + 13) % 26);
            } else {
                str[i] = 'a' + ((str[i] - 'a' + 13) % 26);
            }
        }
    }
    
    cout << str;
    
    return 0;
}