#include <iostream>
using namespace std;

int main(void) {
    int n = 0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        for(int z=0; z<(2*n-1)-i*2; z++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=0; i<n-1; i++) {
        for(int j=i; j<n-2; j++) {
            cout << " ";
        }
        for(int z=0; z<2*(i+1)+1; z++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}