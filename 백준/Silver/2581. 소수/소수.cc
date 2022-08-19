#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void primeNumber(int m, int n, vector<int>& v1) {
    int min = 0;
    for(int i=m; i<=n; ++i) {
        bool isPrime = true;
        
        if(i == 1) {
            continue;
        } else if(i == 2 || i == 3) {
            v1.push_back(i);
            continue;
        }
        
        for(int j=2; j<=(int)sqrt(i); ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            v1.push_back(i);
        }
    }
}

int main(void) {
    int m,n;
    int sum = 0;
    vector<int> v1;
    
    cin >> m >> n;
    primeNumber(m, n, v1);
    
    if(v1.size() == 0)
        cout << -1;
    else {
        for(int i:v1)
            sum += i;
        cout << sum << '\n' << v1.front();
    }
    
    return 0;
}