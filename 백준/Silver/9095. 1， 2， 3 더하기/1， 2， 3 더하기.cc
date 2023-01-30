#include <iostream>
using namespace std;

int main(void) {
    int a,n=0;
    int arr[11] = {0,1,2,4,};
    
    cin >> n;
    
    for(int i=4; i<=10; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    for(int j=0; j<n; j++) {
        cin >> a;
        cout << arr[a] << "\n";
    }
    
    return 0;
}