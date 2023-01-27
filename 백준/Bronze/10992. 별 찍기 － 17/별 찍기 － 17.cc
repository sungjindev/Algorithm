#include <iostream>
using namespace std;

int main(void) {
    int n=0;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<n-i; j++) {
            cout << " ";
        }
        if(i==1) {
            cout << "*" << "\n";
            continue;
        }
        else if(i>=2 && i<n) {
            cout << "*";
            for(int z=0; z<2*(i-1)-1; z++) {
                cout << " ";
            }
            cout << "*" << "\n";
            continue;
        }
        else if(i==n) {
            for(int k=0; k<2*n-1; k++) {
                cout << "*";
            }
            cout << "\n";
            break;
        }
    }
    
    return 0;
}