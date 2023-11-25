#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//path가 최대 20만개고 n이 5만개이다. 그럼 대략 n 1개당 4개의 path를 가진다고 했을 때, 만약 1레이어에 4개씩 주루룩 4개 단위로 fully하게 이어져 있다고 치면 대략 5만개/4를 한 것이 레이어의 개수일 것이다. 이게 12500이니까 이걸 완전 탐색하는 경우의 수는 4^12500이다. 완전 탐색은 불가능해보인다.
//그럼 그리디인가? 아니다! 지금 선택의 최소 거리라해도 경로를 끝까지 지나가보면 그 경로가 최소가 아닐 수 있다. 그리디는 안된다.

//그래서 생각난 것이 다익스트라 알고리즘이다. 다익스트라를 일반적으로 짜면 O(n^2)인데 n이 50000이므로 약 25억회의 연산이 걸린다. 이는 대략 25초 정도이므로 시간 초과가 발생할 것이다. 그래서 이를 힙을 이용하는 우선 순위 큐를 사용해서 줄여볼 것이다. 우선순위 큐를 이용해서 구현하였을 때, 동작방식은 인접한 간선들을 모두 Queue에 집어 넣은 후, 최소힙을 구하는 연산을통해서 최소비용이 드는 정점들부터 처리하는 방식이다.이렇게 처리했을 경우, 시간복잡도는 O(E * logN) (E = 간선의 수, N = 정점의 수)이다. 왜냐하면 최소힙을 통해 최소 비용이 드는 정점을 찾는데 드는 비용이 logN인데(트리의 높이) 이걸 모든 간선마다 수행하므로 O(E * logN)이다.

//그리고 문제를 잘 보면 왕복 경로를 구해야하는 것만 같지만 사실은 편도만 구해도 된다. 편도만 구하고 그 길로 그대로 돌아오면 되기 때문이다.

bool isSummit[50001] = {false, };
vector<int> answer(2,10000001);
int dist[50001] = {0, };    //일반적으로 도달할 수 없는 큰 값을 채워줌 (INF 역할)
vector<vector<pair<int, int>>> adj(50001, vector<pair<int, int>>()); //{인접 노드 번호, 비용}이 pair로 있는 벡터의 벡터이다.

void dijkstra(vector<int> gates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(auto gate: gates) {
        pq.push({0, gate});
        dist[gate] = 0;
    }
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > answer[1])
            continue;
        
        if(isSummit[current]) {
            if(answer[1] > cost) {
                answer[1] = cost;
                answer[0] = current;
            } else if(answer[1] == cost && answer[0] > current)
                answer[0] = current;
            continue;
        }
        
        for(int i=0; i < adj[current].size(); i++) {
            int next = adj[current][i].first;
            int nextCost = adj[current][i].second;
            
            nextCost = max(nextCost, cost);
            
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
            
            
        }
    }
    
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    fill(dist, dist+50001, 10000001);
    
    for(auto path: paths) {
        adj[path[0]].push_back({path[1], path[2]});
        adj[path[1]].push_back({path[0], path[2]});
    }
    
    for(auto summit: summits) {
        isSummit[summit] = true;
    }
    
    dijkstra(gates);
    
    return answer;
}
