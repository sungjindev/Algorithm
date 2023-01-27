#include <iostream>
using namespace std;

int main(void) {
    int n=0;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=n-i; j>0; j--) {
            cout << " ";
        }
        for(int u=0; u<i; u++) {
            cout << "* ";
        }
        
        cout << "\n";
    }
    
    return 0;
}