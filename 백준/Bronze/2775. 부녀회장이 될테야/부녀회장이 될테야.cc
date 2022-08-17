#include <iostream>
using namespace std;

int getValue(int k, int n) {
    if(k==0)
        return n;
    if(n==1)
        return 1;
    return getValue(k,n-1) + getValue(k-1,n);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,k,n;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> k >> n;
        cout << getValue(k,n) << "\n";
    }
    
    return 0;
}