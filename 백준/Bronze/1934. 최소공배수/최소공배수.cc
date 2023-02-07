#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
    int r=0;
    while(b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int gcd,a,b,n=0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        gcd = a > b ? GCD(a,b) : GCD(b,a);
        cout << a*b/gcd << "\n";
    }
    
    return 0;
}