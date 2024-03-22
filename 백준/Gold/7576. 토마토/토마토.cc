#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//이 문제는 전형적인 BFS 문제이다.
//최단 경로로 확산되어 나가는 그 문제이기 때문에 BFS로만 풀어야 한다.
//단지 이 문제에서 주의해야 될 것은 토마토가 들어있지 않은 칸 -1도 있음을 주의해야 한다.
//그 외에는 전형적인 BFS 문제이다.

//주의할 점은 처음에 queue에 넣을 때 익은 토마토를 모두 한번에 넣어주고 그 다음 bfs()가 끝나면
//먼저 모든 토마토가 익었는지부터 check()로 확인해준다. 모두 익었다면 visited[][]에서 가장 큰 값이 최소 시간인 것이다.
//모두 익지 못했다면 -1을 출력한다.

#define X first
#define Y second

int board[1000][1000];
int visited[1000][1000];    //이 방문 여부를 확인하는 visited 배열에 dist를 기록해나갈 것이다.(확산 시간)
queue<pair<int, int>> q1;   //BFS를 위한 queue이다.
int m,n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(void) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(board[i][j] == 1) {  //익은 토마토라면
                visited[i][j] = 0;
                q1.push({i,j}); //모두 한번에 queue에 push!
            }
        }
    }
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        for(int i=0; i<4; ++i) {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] != -1 || board[nx][ny] != 0) //배열의 범위를 초과하거나 이미 방문했거나 익지 않은 토마토가 아니라면 Skip!
                continue;
                
            visited[nx][ny] = visited[curr.X][curr.Y] + 1;
            q1.push({nx, ny});
        }
    }
}

bool check(void) {  //여기서 주의할 점이 익은 토마토가 막 퍼지는데 토마토가 없는 장애물 영역 때문에 결국 모두 익기에 실패할 수 있다. 이걸 검증해주는 것이다.
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(board[i][j] != -1 && visited[i][j] == -1)
                return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j]; //지도 채우기
        }
    }
    fill(&visited[0][0], &visited[n-1][m], -1);
    bfs();
    if(check())
        cout << *max_element(&visited[0][0], &visited[n-1][m]);
    else
        cout << "-1";
    return 0;
}