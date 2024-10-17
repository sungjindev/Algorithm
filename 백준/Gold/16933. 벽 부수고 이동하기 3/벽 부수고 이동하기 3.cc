#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

//이전에 풀었던 문제에 낮과 밤이라는 개념이 추가되고 낮에만 벽을 부술 수 있다.
//그래서 처음에 낮과 밤을 어떻게 구분할지에 대해서 먼저 고민했는데, 처음 이동할 때가 낮이라고 했으므로 cost 기준으로 홀수 짝수로 나눠서 낮과 밤을 구분하면 될 것 같다.
//그렇게 구분한 이후에 낮과 밤에 대한 cost 배열을 따로 둬야되는 지를 고민했는데, 그럴 필요가 없을 것 같다.
//그냥 bfs while 루프를 돌 때 현재 낮이면 벽을 부술 수 있는 것이고, 만약 현재 밤이면 벽 부수는 것 없이 이동하거나 아니면 벽을 부술 곳이 있다면
//현재 cost보다 1을 추가로 더한 다음(이게 다음 낮을 기다리는 것) 벽을 부숴 이동하도록 하면 될 것 같다.

//하지만 위처럼 하면 일부 테스트 케이스에서 예외가 발생한다.
//왜냐하면, cost만 1을 추가로 더해줬을 뿐 실제로 queue 순서 상에서 한 턴을 기다린 뒤 넣어주는 게 아니라서 queue의 흐름에 이상이 생겨 나중에
//더 큰 cost로 덮어씌워져 최단 경로가 보장되지 않기 때문이다.
//따라서 기존 bfs 로직을 좀 바꿔서 최단 경로가 애초에 보장되지 않는다는 걸 가정하고 cost를 업데이트 시켜줄 때는 항상 최솟값인지 비교하도록 하고
//bfs 로직을 모두 마친 뒤 최종 목적지 좌표 모든 k에 대하여 최솟값을 찾은 뒤 그 값을 답으로 출력해주도록 하자!!!

#define MAX 99999999

int n,m,k;
queue<tuple<int,int,int>> q1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[1000][1000];
int visited[1000][1000][11];

void bfs(void) {
    visited[0][0][0] = 1;
    q1.push({0,0,0});
    
    while(!q1.empty()) {
        int cx,cy,cw;
        tie(cx,cy,cw) = q1.front();
        q1.pop();
        
        // if(cx == n-1 && cy == m-1) {
        //     cout << visited[cx][cy][cw];
        //     return;
        // }
        
        for(int i=0; i<4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(board[nx][ny] == '0') {  //이동할 곳이 벽이 아닌 경우
                // if(visited[nx][ny][cw]) //이미 이전에 방문한 곳인 경우 bfs라서 최단 경로가 될 수 없음
                //     continue;
                
                if(visited[nx][ny][cw] > visited[cx][cy][cw] + 1) {
                    visited[nx][ny][cw] = visited[cx][cy][cw] + 1;
                    q1.push({nx,ny,cw});
                }
                
                // visited[nx][ny][cw] = visited[cx][cy][cw] + 1;
                // q1.push({nx,ny,cw});
            } else if(board[nx][ny] == '1') {   //이동할 곳이 벽인 경우
                if(cw+1 > k)    //최대로 벽 부술 수 있는 횟수를 초과하는 경우 skip!
                    continue;
                
                // if(visited[nx][ny][cw+1])   //이미 이전에 방문한 곳인 경우 bfs라서 최단 경로가 될 수 없음
                //     continue;
                
                if(visited[cx][cy][cw] % 2 == 1)  {   //cost가 홀수인 경우는 낮이다.
                
                    if(visited[nx][ny][cw+1] > visited[cx][cy][cw] + 1) {
                        visited[nx][ny][cw+1] = visited[cx][cy][cw] + 1;
                        q1.push({nx,ny,cw+1});
                    }
                
                    // visited[nx][ny][cw+1] = visited[cx][cy][cw] + 1;    //따라서 그냥 벽을 부수면 된다.
                    // q1.push({nx,ny,cw+1});
                } else if(visited[cx][cy][cw] % 2 == 0) { //cost가 짝수인 경우는 밤이라서, 하루 기다린 다음 벽을 부술 수 있다.
                
                    if(visited[nx][ny][cw+1] > visited[cx][cy][cw] + 2) {
                        visited[nx][ny][cw+1] = visited[cx][cy][cw] + 2;
                        q1.push({nx,ny,cw+1});
                    }
                
                    // visited[nx][ny][cw+1] = visited[cx][cy][cw] + 2;    //하루 기다리기 때문에 1을 추가로 더해준다.
                    // q1.push({nx,ny,cw+1});
                }
            }
        }
        
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(&visited[0][0][0], &visited[999][999][11], MAX);
    cin >> n >> m >> k;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j];
        }
    }
    
    bfs();
    int min = MAX;
    for(int i=0; i<=k; ++i) {
        if(min > visited[n-1][m-1][i])
            min = visited[n-1][m-1][i];
    }
    
    if(min == MAX)
        cout << "-1";
    else
        cout << min;
    
    return 0;
}