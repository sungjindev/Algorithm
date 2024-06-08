#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n=0;
    string str1;
    
    cin >> n;
    cin >> str1;
    
    char before = str1[0];
    
    for(int i=0; i<n-1; ++i) {
        cin >> str1;
        if(str1[0] != before) {
            cout << "0";
            return 0;
        }
        before = str1[0];
    }
    
    cout << "1";
    return 0;
}