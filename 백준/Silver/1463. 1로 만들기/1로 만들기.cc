#include <iostream>
using namespace std;

int arr[3000000] = {0, };

void calc(int n);

int main(void) {
    int n=0;
    cin >> n;
    
    calc(n);

    return 0;
}

void calc(int n) {
    for(int i=1; i<n; i++) {
        if(!arr[i+1]) {
            arr[i+1] = arr[i]+1;
        } else if(arr[i+1] > arr[i]+1) {
            arr[i+1] = arr[i]+1;
        }
        
        if(!arr[i*2]) {
            arr[i*2] = arr[i]+1;
        } else if(arr[i*2] > arr[i]+1) {
            arr[i*2] = arr[i]+1;
        }
        
        if(!arr[i*3]) {
            arr[i*3] = arr[i]+1;
        } else if(arr[i*3] > arr[i]+1) {
            arr[i*3] = arr[i]+1;
        }
    }
    cout << arr[n];
}