#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,m,x,y;
    cin >> n >> m;
    vector<int> v1(n+1, 0);
    
    for(int z=1; z<=n; z++)
        v1[z] = z;
    
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        swap(v1[x],v1[y]);
    }
    
    for(int j=1; j<v1.size(); j++)
        cout << v1[j] << " ";
    
    
    
    return 0;
}