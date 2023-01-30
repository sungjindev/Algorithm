#include <iostream>
using namespace std;

int main(void) {
    int n=0;
    int arr[1001] = { 0,1,3, };
    cin >> n;
    
    for(int i=3; i<=n; i++) {
        arr[i] = (arr[i-2]*2 + arr[i-1]) % 10007;
    }
    
    cout << arr[n];
}