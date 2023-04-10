#include <iostream>
#define MOD 10007
using namespace std;

int main(void) {
    int n=0;
    int sum=0;
    int arr[1001][10] = {0,};
    
    for(int i=0; i<10; i++) {
        arr[1][i] = 1;
    }
    
    for(int i=0; i<1001; i++) {
        arr[i][0] = 1;
    }
    
    cin >> n;
    
    for(int i=2; i<=n; i++) {
        for(int j=1; j<10; j++) {
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % MOD;
        }
    }
    
    for(int i=0; i<10; i++) {
        sum += arr[n][i]%MOD;
    }
    cout << sum%MOD;
    
    return 0;
}