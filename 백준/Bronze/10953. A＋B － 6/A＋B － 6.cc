#include <iostream>
using namespace std;

int main(void) {
    int a,b,n;
    char temp;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a >> temp >> b;
        cout << a+b << '\n';
    }
    
    return 0;
}