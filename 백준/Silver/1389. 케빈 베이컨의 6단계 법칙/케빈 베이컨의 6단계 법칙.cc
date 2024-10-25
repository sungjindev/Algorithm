#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

//친구 관계는 중복되어 들어올 수 있다고 하니 효율성을 높이기 위해 set으로 인접 리스트를 저장하기
//나머지는 앞선 문제와 똑같다.

set<int> adj[101];
int visited[101];
int n,m,a,b,sum;

void bfs(int k) {
    queue<int> q1;
    
    visited[k] = 0;
    q1.push(k);
    
    while(!q1.empty()) {
        int curr = q1.front();
        q1.pop();
        
        for(auto v: adj[curr]) {
            if(visited[v] != -1)
                continue;
            
            visited[v] = visited[curr] + 1;
            sum += visited[v];
            q1.push(v);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int mini = 99999999;
    int answer;
    cin >> n >> m;
    
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        adj[a].insert(b);   //인접 리스트 생성
        adj[b].insert(a);
    }
    
    for(int i=1; i<=n; ++i) {
        fill(&visited[0], &visited[101], -1);
        sum = 0;
        bfs(i);
        if(sum < mini) {
            mini = sum;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}