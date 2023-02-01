#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string arr[4];
    for(int i=0; i<4; i++) {
        cin >> arr[i];
    }
    
    cout << stol(arr[0]+arr[1]) + stol(arr[2]+arr[3]);
    
    return 0;
}