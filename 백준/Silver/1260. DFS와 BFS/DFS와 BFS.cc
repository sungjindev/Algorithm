#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//이 문제는 기본적인 DFS 순회와 BFS 순회를 할 수 있는지 알아보는 문제이다.
//나는 DFS는 재귀로 구현할 것이고 BFS는 queue를 이용해 구현할 것이다.

//근데 이 문제에서 주의해야될 부분이 순회를 Vertex 번호가 작은 순서 먼저 해야되는데
//인접 리스트에 이를 입력할 때 작은 순서대로 들어오지 않는다. 따라서 정렬을 해줘야 한다.

int n,m,v;

vector<int> adj[1001];
bool visited[1001];

void dfs(int curr) {
    visited[curr] = true;
    cout << curr << " ";
    
    for(auto v: adj[curr]) {
        if(visited[v])
            continue;
        dfs(v);
    }
}

void bfs(int curr) {
    queue<int> q1;
    visited[curr] = true;
    q1.push(curr);
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        cout << curr << " ";
        
        for(auto v: adj[curr]) {
            if(visited[v])
                continue;
            visited[v] = true;
            q1.push(v);
        }
    }
}

int main(void) {
    int a,b;
    cin >> n >> m >> v;
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);    //양방향 그래프이므로
        adj[b].push_back(a);
    }
    
    for(int i=1; i<=n; ++i) {
        sort(adj[i].begin(), adj[i].end()); //순회 순서를 맞춰주기 위해 정렬
    }
    
    dfs(v);
    cout << "\n";
    fill(visited, visited+n+1, false);    //방문 여부 배열 사용했으니 초기화
    bfs(v);
    
    return 0;
}