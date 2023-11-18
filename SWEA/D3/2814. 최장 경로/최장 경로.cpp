#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//dfs 문제이고 특이하게 경로 길이를 구하기 위해 depth(level)을 항상 dfs 파라미터로 함께 넘겨줘야 될 것 같다.

int maxi = 0;

vector<int> visited;
vector<vector<int>> adj; 

void dfs(int v, int depth) {
    depth++;
	visited[v-1] = 1;
    bool isLeef = true;
    for(int i=0; i<adj[v-1].size(); i++) {
        if(!visited[adj[v-1][i]-1]) {
    		dfs(adj[v-1][i], depth);
            isLeef = false;
        }
    }
    visited[v-1] = 0;
    if(isLeef && (depth > maxi)) {
    	maxi = depth;
    }
}

int main(void) {
    int t=0;
    int n, m, x, y;
    cin >> t;
  	for(int i=0; i<t; i++) {
        maxi = 0;
    	cin >> n >> m;
        adj.assign(n,vector<int>());
        
        for(int j=0; j<m; j++) {
        	cin >> x >> y;
            adj[x-1].push_back(y);
            adj[y-1].push_back(x);
        }
        
        for(int z=1; z<=n; z++) {
        	visited.assign(n, 0);
        	dfs(z, 0);
        }
        
        cout << "#" << i+1 << " " << maxi << "\n";
    }

    
	return 0;
}