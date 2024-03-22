#include <iostream>
#include <vector>
using namespace std;

//이 문제는 그래프에서 사이클을 찾는 문제이다.
//DFS를 이용해서 모든 정점에 대해서 cycle을 찾는 과정을 수행해주면 될 것 같다.
//아 참고로 그래프는 방향 그래프이다.

bool visited[1001];
vector<int> adj[1001];

int t,n,cycle;

void dfs(int curr) {
    visited[curr] = true;

    for(auto v: adj[curr]) {
        if(visited[v])
            continue;
        dfs(v);
    }
}

int countCycle(void) {
    for(int i=1; i<=n; ++i) {
        if(visited[i])
            continue;
        dfs(i); //Vertex i를 아직 방문하지 않았으면 해당 정점부터 dfs 시작해서 cycle 찾기
        ++cycle;
    }
    
    return cycle;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int temp;
    cin >> t;
    for(int i=0; i<t; ++i) {
        cycle = 0;
        fill(visited, visited+1001, 0);
        fill(adj, adj+1001, vector<int>());
        cin >> n;
        for(int j=1; j<=n; ++j) {
            cin >> temp;
            adj[j].push_back(temp);  //그래프 모양에 맞게 인접 리스트 채우기
        }
        cout << countCycle() << "\n";
    }
    
    return 0;
}