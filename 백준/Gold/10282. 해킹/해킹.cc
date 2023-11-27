#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//최대 테스트 케이스(t)는 100개 각 테스트 케이스 별 최대 컴퓨터 개수(n)은 10000개 edge를 나타내는 의존성 최대 개수는(d) 100000개
//이는 다익스트라 문제로 풀 수 있다. 우선 순위 큐를 사용한다면 O(100*100000*log10000)이므로 총 최대 연산 회수는 약40000000으로 
//1초 이내에 시간 초과 없이 풀 수 있다.
//이 문제에 핵심은, 감염되는 총 컴퓨터의 대수와 마지막 컴퓨터가 감염되기까지 걸리는 시간을 구하는 것이다.
//다익스트라를 활용해서 Dist를 구한 다음에, 최대 Dist가 가장 마지막 컴퓨터가 감염되는데 걸리는 시간이고,
//초기값인 INF를 가지지 않는 Dist 원소의 개수가 총 감염된 컴퓨터의 대수일 것이다.
//그리고 a,b,s 식으로 a가 b에 의존하며, s의 시간이 걸린다라고 input이 들어오게 되는데,
//이를 b->a edge로 생각하고 간선의 cost를 s로 생각한다음, 처음 해킹당한 컴퓨터 c를 다익스트라 시작 노드로 생각하면 된다.
//여기서 중요한 게 어떤 a라는 컴퓨터가 감염될 수 있는 경로가 여러개 있다고 할 때,
//시간적인 개념이므로 가장 작은 시간으로 업데이트를 해야한다. 즉 다익스트라 최소비용으로 모든 경로 탐색한다고 생각하면 된다.

//엣지 별 cost인 s의 최대값은 1000이고 최대 컴퓨터 대수가 10000이므로 INF는 1000*10000+1 로 설정하였다.
#define INF (1000*10000+1)

vector<vector<pair<int, int>>> adj; //{도착지 노드, cost}형식으로 edge에 대한 정보를 저장
vector<int> dist;
int c=0;

void dijkstra(void) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{cost, 목적지 노드} 식으로 저장
    
    dist[c] = 0;
    pq.push({0, c});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[current])
            continue;
            
        for(int i=0; i<adj[current].size(); ++i) {
            int next = adj[current][i].first;
            int nextCost = adj[current][i].second + cost;
            
            if(nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    
}

int main(void) {
    int t=0;
    int n,d,a,b,s;
    cin >> t;
    for(int i=0; i<t; ++i) {
        cin >> n >> d >> c;
        adj.assign(n+1, vector<pair<int, int>>());
        dist.assign(n+1, INF);
        for(int j=0; j<d; ++j) {
            cin >> a >> b >> s;
            adj[b].push_back({a,s});
        }
        int count=0;
        dijkstra();
 
        for(int z=0; z<dist.size(); ++z) {
            if(dist[z] == INF) {
                dist[z] = -1;
            } else {
                count++;
            }
        }
        
        cout << count << " " << *max_element(dist.begin(), dist.end()) << "\n";
    }
    
    return 0;
}