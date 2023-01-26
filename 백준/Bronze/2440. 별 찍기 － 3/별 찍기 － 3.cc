#include <iostream>
using namespace std;

int main(void) {
    int n = 0;
    cin >> n;
    for(int i=n; i>0; --i) {
        for(int j=0; j<i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}