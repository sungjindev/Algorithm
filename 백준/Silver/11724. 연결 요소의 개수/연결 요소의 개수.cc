#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> v1;
int n,m;
vector<int> check;

void checkComponent(int x) {
    if(check[x-1])
        return;
    check[x-1]=1;
    for(int i=0; i < v1[x-1].size(); i++) {
        if(!check[v1[x-1][i]-1])
            checkComponent(v1[x-1][i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b;
    int count = 0;
    cin >> n >> m;
    v1 = vector<vector<int>>(n,vector<int>());
    check = vector<int>(n,0);

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        v1[a-1].push_back(b);
        v1[b-1].push_back(a);
    }
    
    for(int z=0; z<n; z++) {
        if(!check[z]) {
            checkComponent(z+1);
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}