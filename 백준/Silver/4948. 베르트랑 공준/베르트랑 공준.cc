#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime[123456*2+1] = {false};

void primeNumber(int m, int n) {
    for(int i=m; i<=n; ++i) {
        bool isPrime = true;
        
        if(i == 1) {
            continue;
        } else if(i == 2 || i == 3) {
            checkPrime[i] = true;
            continue;
        }
        
        for(int j=2; j<=(int)sqrt(i); ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            checkPrime[i] = true;
        }
    }
}

int main(void) {
    int n;
    primeNumber(1, 123456*2);
    while(1) {
        int count = 0;
        cin >> n;
        if(!n)
            break;
        for(int i=n+1; i<=2*n; i++) {
            if(checkPrime[i])
                count++;
        }
        cout << count << '\n';
    }
    return 0;
}