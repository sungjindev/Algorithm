#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,a,b,accum;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> a >> b;
        accum = 1;
        for(int j=0; j<b; j++) {
            accum *= a;
            accum = accum%10;
        }
        if(accum == 0)
            cout << "10" << "\n";
        else
            cout << accum << "\n";
    }
    
    return 0;
}