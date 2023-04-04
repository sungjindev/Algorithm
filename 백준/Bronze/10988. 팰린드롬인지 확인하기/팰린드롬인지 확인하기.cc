#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    string str1, str2;
    
    cin >> str1;
    str2 = str1;
    reverse(str1.begin(), str1.end());
    
    if(str1 == str2)
        cout << "1";
    else
        cout << "0";
    
    return 0;
}