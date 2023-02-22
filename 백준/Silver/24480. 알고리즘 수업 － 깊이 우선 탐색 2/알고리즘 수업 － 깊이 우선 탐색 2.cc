#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,r;
int cnt;
vector<vector<int>> adj;
vector<int> check;
vector<int> order;

void dfs(int num) {
    for(int i=0; i<adj[num-1].size(); i++) {
        if(!check[adj[num-1][i]-1]) {
            check[adj[num-1][i]-1] = 1;
            order[adj[num-1][i]-1] = ++cnt;
            dfs(adj[num-1][i]);
        }
    }
}

int main(void) {
    int u,v;
    cin >> n >> m >> r;
    adj = vector<vector<int>>(n,vector<int>());
    order = vector<int>(n,0);
    check = vector<int>(n,0);

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u-1].push_back(v);
        adj[v-1].push_back(u);
    }
    
    for(int i=0; i<n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }
        
    check[r-1] = 1;
    order[r-1] = ++cnt;
    dfs(r);
    
    for(int z=0; z<n; z++) {
        cout << order[z] << "\n";
    }
    
    
    return 0;
}