#include <iostream>
using namespace std;

int main(void) {
    int n,m;
    int i,j,k;
    int basket[101] = {0, };
    cin >> n >> m;
    
    for(int t=0; t<m; t++) {
        cin >> i >> j >> k;
        for(int z=i; z<=j; z++) {
            basket[z] = k;
        }
    }
    
    for(int x=1; x<=n; x++) {
        cout << basket[x] << " ";
    }
    return 0;
}