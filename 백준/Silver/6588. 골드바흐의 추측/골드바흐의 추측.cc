#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001] = {0,};

void oddEratos(void) {
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i=2; i<=sqrt(1000000); i++) {
        if(arr[i])
            continue;
        
        for(int j=2*i; j<=1000000; j+=i) {
            arr[j] = 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n=0;
    oddEratos();
    while(cin >> n) {
        int i=0;
        if(n==0)
            return 0;
        
        for(i=n-1; i>=(n+1)/2; i--) {
            if(!arr[i] && !arr[n-i]) {
                cout << n << " = " << n-i << " + " << i << "\n";
                break;
            }
        }
        if(i<(n+1)/2)
            cout << "Goldbach's conjecture is wrong." << "\n";
    }
    
    return 0;
}