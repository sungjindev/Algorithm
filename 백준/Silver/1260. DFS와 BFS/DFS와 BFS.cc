#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v1;
int n,m,v;

void dfs(void) {
    vector<int> check(n,0);
    stack<int> s1;
    s1.push(v);
    check[v-1]=1;
    cout << v << " ";
    
    while(!s1.empty()) {
        int min=1001;
        
        if(!v1[s1.top()-1].size()) {
            s1.pop();
            continue;
        }
        
        for(int i=0; i<v1[s1.top()-1].size(); i++) {
            if((v1[s1.top()-1][i] < min) && !check[v1[s1.top()-1][i]-1])
                min = v1[s1.top()-1][i];
        }
        
        if(min != 1001) {
            s1.push(min);
            check[min-1]=1;
            cout << min << " ";
        } else {
            s1.pop();
            continue;
        }
    }
}

void bfs(void) {
    queue<int> q1;
    vector<int> check(n,0);
    q1.push(v);
    
    while(!q1.empty()) {
        for(int i=0; i<v1[q1.front()-1].size(); i++) {
            if(!check[v1[q1.front()-1][i]-1]) {
                q1.push(v1[q1.front()-1][i]);
            }
        }
        
        if(!check[q1.front()-1]) {
            check[q1.front()-1] = 1;
            cout << q1.front() << " ";
        }
        q1.pop();
    }
}

int main(void) {
    int a,b;
    cin >> n >> m >> v;
    v1= vector<vector<int>>(n,vector<int>());
    
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        v1[a-1].push_back(b);
        v1[b-1].push_back(a);
    }
    
    for(int j=0; j<n; j++) {
        sort(v1[j].begin(), v1[j].end());
    }
    
    dfs();
    cout << "\n";
    bfs();
    
    return 0;
}