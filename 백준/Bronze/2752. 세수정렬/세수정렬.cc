#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int a;
    int arr[3];
    
    for(int i=0; i<3; ++i) {
        cin >> a;
        arr[i] = a;
    }
    
    sort(arr, arr+3);
    
    for(auto v: arr)
        cout << v << " ";
    
    return 0;
}
