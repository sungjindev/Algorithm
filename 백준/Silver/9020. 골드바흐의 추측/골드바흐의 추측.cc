#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime[10001] = {false};

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
    int t,n;
    cin >> t;
    primeNumber(1,10001);
    
    for(int i=0; i<t; i++) {
        int minDist = 10001;
        int minNum = 10001;
        cin >> n;
        for(int j=1;j<=n/2; j++) {
            if(checkPrime[j] && checkPrime[n-j]) {
                if(n-j-j < minDist) {
                    minDist = n-j-j;
                    minNum = j;
                }
            }
        }
        cout << minNum << " " << n-minNum << '\n';
    }
    
    
    return 0;
}