#include <iostream>
using namespace std;

int main(void) {
    int a,b;
    
    while(1) {
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        if(a == 0 || b == 0) {
            cout << "neither" << '\n';
            continue;
        }
        
        if(b%a == 0) {
            cout << "factor" << '\n';
            continue;
        } else if(a%b == 0) {
            cout << "multiple" << '\n';
            continue;
        } else {
            cout << "neither" << '\n';
            continue;
        }
    }
    
    return 0;
}