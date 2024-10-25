#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//문제 조건에서 몇 사람을 통하면 서로가 모두 알 수 있다고 했으므로, 각 사람에 대해서 끝까지 모든 사람을 알지 못하는 경우는 고려하지 않아도 된다.
//따라서 그냥 각 회원 별로 순회하면서 bfs를 돌고 bfs의 visited에는 cost를 1씩 증가시켜가자
//그 후 bfs가 끝나면 visited 중에서 가장 높은 cost가 해당 회원의 점수이다.
//참고로 여기서 dfs를 하면 절대 안된다. 왜냐하면, 회원의 점수를 정할 때 더 작은 점수를 기준으로 점수가 매겨진다고 문제에서 언급했으므로
//사실상 친구 관계 간에 최단 경로로 점수를 매겨야 하기 때문이다.
//이렇게 얻은 각 회원별 점수는 배열에 저장하고 0이 아닌 최소 value를 찾고 해당 value를 가지고 있는 모든 후보자를 출력하자.

vector<int> adj[51];
int visited[51];
int result[51];
int n,a,b;

void bfs(int k) {
    queue<int> q1;
    
    visited[k] = 0;
    q1.push(k);
    
    while(!q1.empty()) {
        int curr = q1.front();
        q1.pop();
        
        for(auto v: adj[curr]) {
            if(visited[v] != -1)  //이미 방문했다면 그게 최단 경로이므로 skip!
                continue;
                
            visited[v] = visited[curr] + 1;
            q1.push(v);
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int mini = 99999999;
    set<int> s1;
    cin >> n;
    
    while(1) {
        cin >> a >> b;
        if(a == -1 && b == -1)
            break;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1; i<=n; ++i) {
        fill(&visited[0], &visited[51], -1); //재활용해서 쓰기 때문에 매번 초기화
        bfs(i);
        result[i] = *max_element(visited, visited+51);
        if(result[i] < mini)
            mini = result[i];   //효율적으로 바로 minimum cost 찾아버리기 (이게 회장의 점수)
    }
    
    for(int i=1; i<=n; ++i) {
        if(result[i] == mini) {
            s1.insert(i);
        }
    }
    
    cout << mini << " " << s1.size() << "\n";
    for(auto s: s1)
        cout << s << " ";
    
    return 0;
}