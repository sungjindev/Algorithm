#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1;
    while(getline(cin,str1)) {
        cout << str1 << "\n";
    }
    
    return 0;
}