#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//문제 조건을 보면 반드시 거쳐야하는 두 정점 v1, v2에 대한 정보가 나오는데 이 조건이 오해하기가 쉽다.
//임의의 v1, v2는 같지 않고 v1은 N(끝 노드)가 아니며 v2는 1(첫 노드)가 아니다라는 조건이 나온다.
//다시 생각해보면, v1, v2가 동시에 1이거나 N 등은 안되지만 v1, v2가 각각 1, N인 경우는 가능하다는 이야기가 된다.
//물론 당연히 {1, 1과 N이 아닌 노드}도 가능할 것이다. 
//그래서 이 문제는 특정 2개의 노드를 반드시 거치며 이동해야하는 다익스트라 알고리즘 문제이다.
//이때 이동했던 간선을 이동해도 되고, 방문했던 노드를 또 방문해도 된다고 나와있는데 이건 어차피 간선 사이 비용이 양수라서
//최단 경로를 위해서는 재방문할 일이 없으므로 딱히 신경쓰지 않아도 된다.
//그냥 이 조건은 반드시 거쳐야하는 두 정점을 거치러 갈 때, 그 정점이 한 노드를 통해서만 왔다갔다 할 수 있는 고립된 정점이라면
//특정 노드를 2번 방문해야해서 생긴 조건인 것 같다.
//다익스트라 알고리즘의 시간 복잡도는 우선 순위 큐를 활용해서 구현했을 경우 O(E * logN)이므로 O(200000 * log800)=O(600000이하)
//약 50~60만 회의 연산이 진행되므로 시간 초과 걱정은 없다.

//이제 이 문제를 푸는 알고리즘에 집중해서 알아보겠다. 특정 두 정점을 반드시 자나며 최단 경로를 구해야하고,
//특정 두 정점에 대한 조건은 위에서 살펴본 것처럼 {1,1}, {N,N}인 경우를 제외하고 모두 가능하다. 이름 참고해서 경우를 나눠 구현할 것이다.
//1 또는 N인 경우 무조건 시작과 끝에 거치게 되므로, 제외하고 나머지 정점들에 대해서만 계산을 하면된다.
//첫번째 경우, 둘 다 1 또는 N인 경우이다. 이 경우엔, Input Node로 1을 넣고 다익스트라해서 Dist[N] 구하면 된다.
//두번째 경우, 둘 중에 하나만 1 또는 N인 경우이다. 이 경우엔, 1 또는 N이 아닌 노드를 먼저 거친 뒤 N으로 가면 된다.
//세번째 경우, 둘 다 1 또는 N이 아닌 경우이다. 이 경우엔, 2가지 케이스가 있다. v1 거친후 v2로 이동하는 방법과 v2 거친후 v1으로 가는 것.
//즉, 1->v1->v2->N과 1->v2->v1->N이 있다. 이를 위해 Input 1일 때 Dist, Input v1일 때 Dist, Input v2일 때 Dist를 따로 구해줘야 한다.
//이거 구하기 위한 Dijkstra 메소드에 파라미터로 start index, end index, dist는 가지면 좋을 것 같다. 안그래도 상관은 없긴한데,
//end index를 주면,연산 횟수를 줄일 수 있다.

#define INF 200000001   //그냥 간단하게 최대 edge * 최대cost +1로 계산

vector<pair<int, int>> adj[801]; //{종착지 노드, 코스트} pair로 인접 리스트 저장!

void dijkstra(int start, int end, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{지금까지의 코스트, 다음 노드}꼴로 pq에 저장
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(dist[current] < cost || current == end)
            continue;
        
        for(int i=0; i<adj[current].size(); ++i) {
            int next = adj[current][i].first;
            int nextCost = cost + adj[current][i].second;
            
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    return;
}
    
int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
    int n,e,a,b,c,v1,v2;
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    v1>v2 ? (swap(v1,v2),0) : 0;
    
    if(v1==1 && v2==n) {
        //둘 다 1 혹은 n인 경우
        vector<int> dist1(n+1, INF);
        dijkstra(1, n, dist1);
        
        if(dist1[n] == INF) {
            cout << "-1";
            return 0;
        } else {
            cout << dist1[n];
            return 0;
        }
    } else {
        vector<int> dist1(n+1, INF);
        vector<int> dist2(n+1, INF);
        if(v1==1 && v2!=n) {
            //하나만 1인 경우
            dijkstra(1, v2, dist1);
            dijkstra(v2, n, dist2);
            
            if(dist1[v2] == INF || dist2[n] == INF) {
                cout << "-1";
                return 0;
            } else {
                cout << dist1[v2]+dist2[n];
                return 0;
            }
        } else if(v1!=1 && v2==n) {
            //하나만 n인 경우
            dijkstra(1, v1, dist1);
            dijkstra(v1, n, dist2);
            
            if(dist1[v1] == INF || dist2[n] == INF) {
                cout << "-1";
                return 0;
            } else {
                cout << dist1[v1]+dist2[n];
                return 0;
            }
        } else {
            //v1, v2 둘 다 1 또는 n이 아닌 경우
            int min = INF;
            vector<int> dist3(n+1, INF);
            dijkstra(1, v1, dist1);
            dijkstra(v1, v2, dist2);
            dijkstra(v2, n, dist3);
            
            if(dist1[v1]==INF || dist2[v2]==INF || dist3[n]==INF) {
                cout << "-1";
                return 0;
            } else {
                min = min > (dist1[v1]+dist2[v2]+dist3[n]) ? (dist1[v1]+dist2[v2]+dist3[n]) : min;
            }
            
            dist1.assign(n+1, INF);
            dist2.assign(n+1, INF);
            dist3.assign(n+1, INF);
            
            dijkstra(1, v2, dist1);
            dijkstra(v2, v1, dist2);
            dijkstra(v1, n, dist3);
            
            if(dist1[v2]==INF || dist2[v1]==INF || dist3[n]==INF) {
                cout << "-1";
                return 0;
            } else {
                min = min > (dist1[v2]+dist2[v1]+dist3[n]) ? (dist1[v2]+dist2[v1]+dist3[n]) : min;
            }
            
            cout << min;
            return 0;
        }
    }
    return 0;
}