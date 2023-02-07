#include <iostream>
#include <algorithm>
using namespace std;

int GCD(unsigned long long a, unsigned long long b) {
    unsigned long long r=0;
    while(b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    unsigned long long a, b, n;
    cin >> a >> b;
    
    n = a>b ? GCD(a,b) : GCD(b,a);
    
    for(int i=0; i<n; i++) {
        cout << "1";
    }

    return 0;
}