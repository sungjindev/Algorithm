//항상 문제 풀 때 변수는 초기화를 반드시 해주자!!!!!!!!!!!! 안했으면 초기화 잘 됐는지 검사하기
//최단 경로를 구해야 하므로 BFS로 풀자
//그리고 가장 먼저 해야될 것은 인접 리스트로 바꿔주는 것이다!
//인접 리스트를 구할 때 노드 번호가 작은 것부터 방문해야 된다는 등의 조건이 없으므로 정렬하지 않아도 된다!!!!
//depth를 구할 때 depth가 초기값(-1)이 아닌 경우에는 업데이트를 하지 말아야한다!!! (그건 최단 경로가 아니기 때문)
//위에처럼 생각했지만 위 로직이 없어도 된다! 왜냐하면 우리는 어차피 visited를 검사 하기 때문에 이미 방문한 노드의 경우에는
//depth를 업데이트해 줄 일이 없기 때문이다!!!!!!!!!!!!
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> visited(n,0);
    vector<vector<int>> adj(n,vector<int>());
    queue<int> q1;
    
    for(int i=0; i<edge.size(); i++) {
        adj[edge[i][0]-1].push_back(edge[i][1]-1);
        adj[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    
    q1.push(0);
    visited[0] = 1;
    
    while(!q1.empty()) {
        for(int i=0; i<adj[q1.front()].size(); i++) {
            if(!visited[adj[q1.front()][i]]) {
                visited[adj[q1.front()][i]] = visited[q1.front()]+1;
                q1.push(adj[q1.front()][i]);
            }
        }
        q1.pop();
    }
    
    int maxlength = *max_element(visited.begin(), visited.end());
    
    for(auto v: visited) {
        if(v==maxlength)
            answer++;
    }
    
    return answer;
}