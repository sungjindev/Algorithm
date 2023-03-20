#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1="";
    int n;
    cin >> n;
    n /= 4;
    
    for(int i=0; i<n; i++) {
        str1 += "long ";
    }
    cout << str1 + "int";
    return 0;
}