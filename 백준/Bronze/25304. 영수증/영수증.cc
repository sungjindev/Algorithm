#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x,n,a,b;
    int total = 0;
    
    cin >> x >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        total += a*b;
    }
    
    if(total == x)
        cout << "Yes";
    else
        cout << "No";
    

    return 0;
}