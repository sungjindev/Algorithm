#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//이 문제도 전형적인 BFS 문제이다.
//촌수를 계산하기 위해 인접 리스트를 구하고
//거기서 BFS를 돌려 최단 길이를 찾는다.

int n,m,a,b;
vector<int> adj[101];
int visited[101];
queue<int> q1;

void bfs(void) {
    visited[a] = 1;
    q1.push(a);
    
    while(!q1.empty()) {
        int curr = q1.front();
        q1.pop();
        if(curr == b)
            break;
            
        for(int v: adj[curr]) {
            if(!visited[v]) {
                visited[v] = visited[curr] + 1;
                q1.push(v);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y;
    cin >> n >> a >> b >> m;
    for(int i=0; i<m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    bfs();
    if(visited[b] != 0)
        cout << visited[b]-1;
    else
        cout << -1;
    
    return 0;
}