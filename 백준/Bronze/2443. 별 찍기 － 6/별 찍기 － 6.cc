#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
 
    for(int i=n; i>=0; --i) {
        for(int j=n-i; j>0; --j) {
            cout << " ";
        }
        for(int k=2*i-1; k>0; --k) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}