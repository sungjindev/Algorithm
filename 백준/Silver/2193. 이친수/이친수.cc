#include <iostream>
using namespace std;

int main(void) {
    long long end0[91] = {0, };
    long long end1[91] = {0, };
    int n=0;
    
    cin >> n;
    
    end0[1] = 0;
    end1[1] = 1;
    end0[2] = 1;
    end1[2] = 0;
    end0[3] = 1;
    end1[3] = 1;
    
    for(int i=4; i<=n; i++) {
        end0[i] = end0[i-1] + end1[i-1];
        end1[i] = end0[i-1];
    }
    
    cout << end0[n] + end1[n];
    
    return 0;
}