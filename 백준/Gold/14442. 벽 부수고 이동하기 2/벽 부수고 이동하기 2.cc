#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

//최단 경로를 구해야되기 때문에 일단 BFS로 풀어야 하는 것은 맞다.
//하지만 일반적인 BFS처럼 Visited 배열을 만들어서 각 좌표에 대한 cost를 항상 최솟값으로 유지시켜주며 업데이트시켜줘선 안된다.
//왜냐하면 벽을 초반에 뿌수냐 나중에 뿌수냐에 따라서 최종 목적지에 도착할 수 있을지 없을지가 달라지기 때문이다.
//예를 들어 초반에 계속 벽을 부수며 최단 cost로 이동중인 경로가 마지막에 벽으로 둘러쌓인 목적지에 마주한다면 결국 도착지에 도착하지 못한다.
//따라서 이때는 cost가 중요한 게 아니고 우선 도착지까지 도착할 수 있는지가 중요한 것이다.

//아니다, 항상 최솟값으로 업데이트 시켜주되 visited 배열을 평소처럼 2차원 배열인 [행 좌표][열 좌표]에 대한 값으로 저장하지 말고
//아래와 같이 3차원 배열로 관리해줘야 된다.
//즉 BFS로 최단 경로에 대한 순회를 이어가되, 벽을 부술지 안부술지 두가지 케이스에 대해 모두 고려하며 queue에 넣어주고,
//visited 배열도 3차원 배열로 관리해줘야 된다. [행 좌표][열 좌표][벽을 부순 횟수] 이런 식으로 각각 좌표에 대해서도 벽을 부순 횟수를 기준으로
//차원을 나눠서 따로 저장해야 된다. 그리고 이 배열에 기존 bfs 로직과 같이 최소 cost가 들어오면 업데이트 시켜주면 되고,
//최종 결과값은 모든 벽을 부순 횟수에 대해 도착지 좌표에 대한 cost를 순회하고 그 중 최솟값을 리턴하면 된다.
//아니다 어차피 BFS 로직이므로, BFS while 문 돌 때 가장 먼저 목적지에 도착한 좌표가 최소 cost이다!!!!!!!!!

#define MAX 99999999

char board[1000][1000];
int visited[1000][1000][11];    //최대가 10번까지 벽을 부술 수 있으므로 0번째 인덱스는 안부순 거, 1번째는 1번 부순거 마지막 10번 인덱스는 10번 다 부순 것이다.
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m,k;
queue<tuple<int,int,int>> q1;

void bfs(void) {
    visited[0][0][0] = 1;
    q1.push({0,0,0});
    
    while(!q1.empty()) {
        int cx,cy,cw;
        tie(cx,cy,cw) = q1.front();
        q1.pop();
        
        if(cx == n-1 && cy == m-1) {
            cout << visited[cx][cy][cw];
            return;
        }
        
        for(int i=0; i<4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(board[nx][ny] == '0') {    //다음 이동할 위치가 벽이 아닌 경우
                if(visited[nx][ny][cw] != 0)  //초기값이 아니라는 것은 이미 이전에 방문해서 cost가 더 작을 것이므로
                    continue;
                visited[nx][ny][cw] = visited[cx][cy][cw]+1;
                q1.push({nx,ny,cw});
            } else if(board[nx][ny] == '1'){  //다음 이동할 위치가 벽인 경우
                if(cw+1 > k)    //최대로 벽 부술 수 있는 횟수를 초과하는 경우
                    continue;
                
                if(visited[nx][ny][cw+1] != 0)
                    continue;
                    
                visited[nx][ny][cw+1] = visited[cx][cy][cw]+1;
                q1.push({nx,ny,cw+1});
            }
        }
    }
    
    cout << "-1";
    return;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j];
        }
    }
    
    bfs();
    
    return 0;
}