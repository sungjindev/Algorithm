#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a,b;
    
    cin >> n;
    
    a = n / 5;
    while(1) {
        if(a < 0) {
            cout << -1;
            return 0;
        }
        if((n - a*5) % 3 == 0) {
            b = (n - a*5) / 3;
            break;
        }
        a--;
    }
    cout << a+b;
    return 0;
}