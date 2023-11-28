#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

//이 문제의 핵심 알고리즘을 떠올리기 위해서는 두 평면 좌표 상의 최단 거리에 대해 고민해볼 필요가 있다.
//두 평면 좌표 상의 최단 거리는 당연히 직선 거리이다. 하지만, 여기에 대포를 이용할 경우에는 대포의 속도가 빠르기 때문에
//적당히 가까운 거리의 위치에 있는 대포의 경우 대포를 타는 것이 최단 경로로 가는데 더 도움이 되기도 한다.
//즉, 이를 다시 생각해보면, 대포를 타거나, 아님 목적지까지로 직선으로 가거나 이 두가지 케이스 경우 밖에 없는 것이다.
//그렇기 때문에 나는, 시작점, 각 대포, 종착점 이렇게 세 가지의 종류를 모두 노드로 삼고 여기에 Dijkstra Algorithm을 사용해서
//최단 시간이 걸리는 경로를 찾아보려고 한다. 즉 cost는 각 간선 별 시간이 될 것이다.
//또 여기서 중요한 것이, 다음 노드로 이동할 때 가장 처음 시작점인 경우에는 무조건 걸어서 이동해야되지만,
//그 이후에는 대포 타고 이동했을 때와 걸어서 이동 모두 가능하므로 둘 중에 minimum cost를 선택하면 된다!!!
//Dijkstra algorithm은 우선 순위 큐를 활용했을 경우에 O(E * logN)이 걸린다. 대포의 숫자 n이 가질 수 있는 최대값은 100이므로
//시작점과 종착점까지 포함해서 총 102개의 노드를 가질 수 있고 각 102개의 노드에 대해서 본인 노드를 제외하고 나머지 노드는
//모두 탐색해야 하는 노드이므로 최대 102*101개의 간선이 생긴다. 이를 계산해보면O(102*101*log102)=약 20000회 정도의 연산이 된다
//이는 역시 시간 초과에 걸리지 않으므로 합리적인 알고리즘이라 생각하여 구현에 들어간다.

int n=0;    //대포의 수

double calcDist(double a, double b) {
    return sqrt(a*a+b*b);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<double, double>> v1;    //{x좌표, y좌표}의 꼴로 노드에 대한 정보를 담을 벡터이다.
    //가장 첫번째 원소는 시작점이고 마지막 원소는 종착점이다. 그 사이에 있는 원소들은 대포이다.
    double x,y,destX, destY;
    cin >> x >> y;
    v1.push_back({x,y});
    cin >> destX >> destY;
    cin >> n;
    vector<double> dist(n+2, 99999.9);
    bool visit[102] = {false,};
    for(int i=0; i<n; ++i) {
        cin >> x >> y;
        v1.push_back({x,y});
    }
    v1.push_back({destX,destY});
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq; //{cost, nodeIndex} 꼴로 오름차순으로저장하도록 구현
    
    dist[0] = 0.0;
    pq.push({0.0, 0});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        double cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[current])
            continue;
            
        if(current == n+1)
            continue;
            
        for(int i=1; i<n+2; ++i) {
            if(i==current)
                continue;
            
            int next = i;
            double nextCost=0.0;
            double distance = calcDist(v1[current].first-v1[next].first, v1[current].second-v1[next].second);
            if(current != 0) {
                nextCost = cost + min(distance/5.0, fabs(distance-50.0)/5.0+2.0);
            } else
                nextCost = cost + (distance/5.0);
            
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
        
    }
    
    cout << dist[n+1];
    
    return 0;
}