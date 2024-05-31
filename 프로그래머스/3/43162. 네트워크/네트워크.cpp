#include <string>
#include <iostream>
#include <vector>
using namespace std;

//bfs로 풀어도 되고 dfs로 풀어도 되는 문제이다.
//이 문제는 그냥 총 연결된 그래프가 몇개 존재하는지 구하는 문제이다.
//나는 그냥 dfs로 풀기로 했다.
//아직 방문하지 않은 노드를 시작으로 연결되어 있는 모든 노드를 dfs를 통해 방문할 것이다.
//이 로직을 반복해서 모든 노드가 방문 처리되면 무한 루프를 탈출하여 answer를 리턴하면 된다.

bool visited[200] = {false, };  //n은 최대 200개 이하이므로 200개로 초기화
vector<vector<int>> adj;

void dfs(int k) {
    for(int i=0; i<adj[k].size(); ++i) {
        if(adj[k][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    adj = computers;    //전역으로 만들어주기 위해
    
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            ++answer;
            visited[i] = true;
            dfs(i);
        }
    }
    
    return answer;
}