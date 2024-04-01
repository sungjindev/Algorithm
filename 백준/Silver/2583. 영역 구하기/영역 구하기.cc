#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이 문제를 처음봤을 때 DFS로 영역에 대한 탐색 및 넓이 계산을 하면 되겠다고 생각했다.
//그래서 재귀 함수를 이용한 DFS로 풀이해보려 한다. 

#define X first
#define Y second

int m,n,k;
bool visited[100][100];
vector<int> areas;  //각 영역의 넓이들을 저장할 벡터
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(pair<int, int> pos) {
    int cnt = 1;    //영역의 개수를 카운팅하기 위해 
    
    for(int i=0; i<4; ++i) {
        int nx = pos.X+dx[i];
        int ny = pos.Y+dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        
        if(!visited[nx][ny]) {
            visited[nx][ny] = true;
            cnt += dfs({nx, ny});
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i=0; i<k; ++i) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j<x2; ++j) {
            for(int k=y1; k<y2; ++k) {
                visited[j][k] = true;
            }
        }
    }
    
    for(int i=0; i<n; ++i) {    //문제 좌표 축에 따라 n,m이 바뀌어야 함
        for(int j=0; j<m; ++j) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                areas.push_back(dfs({i,j}));
            }
        }
    }
    
    sort(areas.begin(), areas.end());
    
    cout << areas.size() << "\n";
    for(auto area: areas)
        cout << area << " ";
    
    
    return 0;
}