#include <iostream>
#include <vector>
using namespace std;

//이 문제는 전형적인 BFS, DFS 문제이다.
//최단 경로를 보장할 필요가 없으므로 DFS로 풀어도 된다. 난 DFS로 풀 것이다.

bool visited[101];
vector<int> adj[101];  //인접 리스트로 간선 정보를 저장
int n,e,answer;

void dfs(int k) {
    for(auto v : adj[k]) {
        if(!visited[v]) {
            ++answer;
            visited[v] = true;
            dfs(v);
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = true;
    dfs(1); //1번 컴퓨터에서 dfs 시작
    cout << answer;
    
    return 0;
}