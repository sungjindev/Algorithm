#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//node가 최대 1000개, edge가 최대 10000개이다.
//priority queue를 활용한 다익스트라 알고리즘을 사용하면 O(edge*logNode) 이므로 30000회 정도 연산이다.
//하지만 여기에서 모든 학생들이 X에 가야하므로 학생수 1000을 더 곱해주면 30000000 = 3천만으로 1초 이내 연산 가능하다.

vector<vector<pair<int, int>>> adj(1001, vector<pair<int, int>>()); //{도착지노드, 소요시간}꼴로 인접리스트 저장
vector<int> dist;

void dijkstra(int departure, int destination, vector<int> &costSum) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //{누적 소요시간, 현재노드}꼴로 pq에 저장
    
    dist[departure] = 0;
    pq.push({0, departure});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > costSum[departure] && costSum[departure] != 0)
            continue;
        
        if(current == destination) {
            if(costSum[departure] > cost || costSum[departure] == 0) {
                costSum[departure] = cost;
                continue;
            }
        }
        
        for(int i=0; i<adj[current].size(); i++) {
            int next = adj[current][i].first;
            int nextCost = cost + adj[current][i].second;
            
            if(nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
        
    }
    
}

void dijkstra2(int departure, int destination, vector<int> &costSum) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //{누적 소요시간, 현재노드}꼴로 pq에 저장
    
    dist[departure] = 0;
    pq.push({0, departure});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > costSum[destination] && costSum[destination] != 0)
            continue;
        
        if(current == destination) {
            if(costSum[destination] > cost || costSum[destination] == 0) {
                costSum[destination] = cost;
                continue;
            }
        }
        
        for(int i=0; i<adj[current].size(); i++) {
            int next = adj[current][i].first;
            int nextCost = cost + adj[current][i].second;
            
            if(nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
        
    }
    
}

int main(void) {
    int n, m, x;
    cin >> n >> m >> x;
    int a,b,t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
    }

    vector<int> costSum(1001,0);
    vector<int> costSum2(1001,0);

    for(int i=1; i<=n; i++) {
        if(i==x)
            continue;
        
        dist.assign(1001, 1000001);
        dijkstra(i,x,costSum);
        dist.assign(1001, 1000001);
        dijkstra2(x,i,costSum2);
    }
    
    for(int i=1; i<=n; i++) {
        costSum[i] += costSum2[i];
    }
    
    cout << *max_element(costSum.begin(), costSum.end());
    
    return 0;
}