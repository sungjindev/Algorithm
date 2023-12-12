#include <iostream>
using namespace std;

int main(void) {
    int p,k;
    cin >> p >> k;
    int i=1;
    for(; ; ++i) {
        if(p==k) {
            break;    
        } else {
            ++k;
        }
    }
    
    cout << i;
    return 0;
}