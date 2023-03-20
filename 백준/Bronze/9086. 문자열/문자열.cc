#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1;
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> str1;
        cout << str1[0] << str1[str1.size()-1] << "\n";
    }
    
    return 0;
}