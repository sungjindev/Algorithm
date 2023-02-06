#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    int r=0;
    while(b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    int a,b,gcdResult;
    cin >> a >> b;
    
    gcdResult = gcd(a,b);
    cout << gcdResult << "\n";
    cout << a*b / gcdResult;
    
    return 0;
}