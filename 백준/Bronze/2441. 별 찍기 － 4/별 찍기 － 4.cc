#include <iostream>
using namespace std;

int main(void) {
    int n = 0;
    cin >> n;
    for(int i=n; i>0; --i) {
        for(int j=n-i; j>0; j--) {
            cout << " ";
        }
        for(int z=0; z<i; z++) {
            cout << "*";
        }
        cout << "\n"; 
    }
    return 0;
}