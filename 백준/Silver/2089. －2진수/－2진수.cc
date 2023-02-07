#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n=0;
    string result="";
    cin >> n;
    
    if(n == 0) {
        cout << "0";
        return 0;
    }
    
    while(n != 0) {
        if(n % -2 == 0) {
            result += "0";
            n /= -2;
        } else {
            result += "1";
            n = (n-1)/-2;
        }
    }
    
    reverse(result.begin(), result.end());
    
    cout << result;
    return 0;
}