#include <iostream>
using namespace std;

int main(void) {
    int n = 0;
    int fact = 1;
    cin >> n;
    if(!n) {
        cout << 1;
        return 0;
    }
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    cout << fact;
    return 0;
}