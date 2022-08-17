#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int t,a,b;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> a >> b;
        cout << a+b << '\n';
    }
    
    return 0;
}