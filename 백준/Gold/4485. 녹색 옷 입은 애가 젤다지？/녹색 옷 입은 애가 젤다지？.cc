#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//n은 최대 125이다. 따라서 최대 125^2 번 방문하여 각 최대 9씩 루피를 잃을 수 있다.
//즉, 125*125*9가 최대로 잃을 수 있는 루피이다. 이것보다 크게 INF를 잡아야 할 것이다. 그래서 아래와 같이 INF를 설정해줬다!
#define INF (125*125*9+1)

vector<vector<int>> adj;
int n=0;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void dijkstra(vector<vector<int>> &dist) {
    //일반적인 다익스트라 문제 같은 경우에는 노드 번호 1개만 필요해서 pair<cost, nodeInd> 이런 식으로 해결이 되는데
    //이 문제 같은 경우에는 노드를 특정하기 위해서 2차원 배열이다보니 인덱스가 2차원으로 필요해서 pair<cost, pair<행, 열>> 이렇게 구현
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    dist[0][0] = adj[0][0];
    pq.push({adj[0][0], {0,0}});
    
    while(!pq.empty()) {
        auto current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[current.first][current.second])
            continue;
        
        for(int i=0; i<4; ++i) {
            if( 0 <= current.first+dx[i] && current.first+dx[i] <= n-1 && 0 <= current.second+dy[i] && current.second+dy[i] <= n-1) {
                pair<int, int> next = {current.first+dx[i], current.second+dy[i]};
                int nextCost = cost+adj[next.first][next.second];
                
                if(nextCost < dist[next.first][next.second]) {
                    dist[next.first][next.second] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        
    }
    
}

int main(void) {
    int temp=0;
    
    for(int z=1; ; ++z) {
        cin >> n;
        
        if(n==0)
            break;
        
        adj.assign(n, vector<int>(n, 0));
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cin >> temp;
                adj[i][j] = temp;
            }
        }
        dijkstra(dist);
        cout << "Problem " <<  z << ": " << dist[n-1][n-1] << "\n";
    }
    
    return 0;
}