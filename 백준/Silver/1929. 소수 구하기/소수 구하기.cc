#include <iostream>
#include <cmath>
using namespace std;

void primeNumber(int m, int n) {
    for(int i=m; i<=n; ++i) {
        bool isPrime = true;
        
        if(i == 1) {
            continue;
        } else if(i == 2 || i == 3) {
            cout << i << '\n';
            continue;
        }
        
        for(int j=2; j<=(int)sqrt(i); ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            cout << i << '\n';
        }
    }
}

int main(void) {
    int m,n;
    cin >> m >> n;
    
    primeNumber(m, n);
    return 0;
}