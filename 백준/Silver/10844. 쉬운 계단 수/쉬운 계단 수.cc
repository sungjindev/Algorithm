#include <iostream>
using namespace std;

int arr[101][10] = {0,};

void calc(int n) {
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j==0) {
                arr[i][0] = arr[i-1][1] % 1000000000;
            } else if(j==9) {
                arr[i][9] = arr[i-1][8] % 1000000000;
            } else {
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
            }
        }
    }
}

int main(void) {
    int n=0;
    int sum = 0;
    
    for(int i=1; i<=9; i++) {
        arr[1][i] = 1; 
    }
    
    cin >> n;
    
    calc(n);
    
    for(int j=0;j<=9; j++) {
        sum += arr[n][j];
        sum %= 1000000000;
    }
    
    cout << sum;
    
    return 0;
}