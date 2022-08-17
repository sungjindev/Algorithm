#include <iostream>
using namespace std;

int main(void) {
    int arr[5] = {0};
    int sum = 0;
    for(int i=0; i<5; i++) {
        cin >> arr[i];
        sum += arr[i] * arr[i];
    }
    
    cout << sum%10;
    
    return 0;
}