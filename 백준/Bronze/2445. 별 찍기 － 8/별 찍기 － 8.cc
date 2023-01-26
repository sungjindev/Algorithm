#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        for(int u=0; u<i; u++) {
            cout << "*";
        }
        for(int d=0; d<(n-i)*2; d++) {
            cout << " ";
        }
        for(int f=0; f<i; f++) {
            cout << "*";
        }
        cout << "\n";
    }
    for(int j=0; j<n*2; j++) {
        cout << "*";
    }
    cout << "\n";
    for(int i=1; i<n; i++) {
        for(int u=n-i; u>0; u--) {
            cout << "*";
        }
        for(int d=0; d<i*2; d++) {
            cout << " ";
        }
        for(int f=n-i; f>0; f--) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}