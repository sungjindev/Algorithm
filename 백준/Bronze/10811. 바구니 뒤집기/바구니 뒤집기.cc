#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,m,x,y;
    cin >> n >> m;
    vector<int> v1(n+1);
    for(int i=1; i<n+1; i++)
        v1[i] = i;
    
    for(int j=0; j<m; j++) {
        cin >> x >> y;
        reverse(v1.begin()+x, v1.begin()+y+1);
    }
    
    for(int z=1; z<n+1; z++)
        cout << v1[z] << " ";
    
    
    return 0;
}