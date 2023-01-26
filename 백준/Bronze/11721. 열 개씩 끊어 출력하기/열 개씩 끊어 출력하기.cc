#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1;
    int i = 0;
    getline(cin, str1);
    
    for(i=0; i+10<str1.size(); i+=10) {
        cout << str1.substr(i,10) << endl;
    }
    cout << str1.substr(i);
    
    return 0;
}