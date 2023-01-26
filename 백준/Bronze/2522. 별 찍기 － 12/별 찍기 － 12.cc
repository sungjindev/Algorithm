#include <iostream>
using namespace std;

int main(void) {
    int n = 0;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<n-i; j++) {
            cout << " ";
        }
        for(int z=0; z<i; z++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        for(int z=0; z<n-i; z++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}