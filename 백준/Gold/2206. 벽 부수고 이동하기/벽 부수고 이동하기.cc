#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

//우선 이 문제는 최단 경로를 구하는 전형적인 BFS 문제이다.
//하지만 조금 특별한 조건이 있는데, 이동하는 경로 중에서 최대 1번은 벽을 부수고 이동할 수 있다는 점이다.
//BFS는 보통 큐에 계속해서 넣고 빼면서 최단 경로 길이를 구하게 되는데
//그 과정에서 직전 경로까지 벽을 부쉈는지 안뿌쉈는지 여부를 각각 별도로 저장해줘야 된다.

//이 문제에서 가벼운 함정 하나! 입력값이 공백으로 구분되어 있지 않고 붙어있다. 그래서 string을 써서 int로 처리해도 되고
//아니면 char형으로 받아도 된다. 나는 char형으로 받도록 하였다.

//이 문제에서 그리고 가장 주의해야할 것은, 일반적인 BFS랑 다르게 벽을 부스는 일을 통해 당장은 최단 경로가 아니더라도,
//이게 나중엔 최단 경로가 될 수 있다는 점이다. 그러므로, 현재 최단 경로가 맞는지 아닌지 여부에 따라 queue에 push 할 게 아니고
//모두 push 해주고 나중에 최단 경로 비용을 찾는 방식으로 구현해야한다.
//왜냐하면, 여기서 가장 중요한건 최종 도착지에 최단 비용도 맞지만, 중간 과정에서는 지금까지 최단 비용인지가 중요한 게 아니고
//지금까지 벽을 부셨는지 안부셨는지가 더 중요할 수 있다. 왜냐하면, 벽을 안부수면 그 뒤에서 언제든지 최단 비용 거리를 뒤집을 수도 있기 때문이다.
//그래서 벽을 부쉈을 때 dist랑 벽을 부수지 않았을 때 dist를 따로 저장하기로 한다.
//이렇게 따로 저장하면, 최단 dist를 구하면서 지금까지 벽을 부쉈는지 안부쉈는지 여부도 쉽게 관리할 수 있기 때문이다.

char board[1000][1000];
int dist[1000][1000][2];    //dist[x][y][0]이 벽을 하나도 부수지 않고 x,y로 오는 비용, dist[x][y][1]이 벽을 한번 부수고 x,y로 오는 비용
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = -1;
    
    queue<tuple<int, int, int>> q1; //튜플 3번째 원소가 벽 부쉈는지 여부! 0은 안부순 것
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j];
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    
    dist[0][0][0] = dist[0][0][1] = 1;
    q1.push({0,0,0});   //튜플 3번째 원소가 벽 부쉈는지 여부! 0은 안부순 것, 1은 부순 것

    while(!q1.empty()) {
        int cx,cy,cf;
        tie(cx,cy,cf) = q1.front();
        q1.pop();

        if(cx == n-1 && cy == m-1) {
            answer = dist[cx][cy][cf];
            break;
        }
        
        int nextDist = dist[cx][cy][cf]+1;

        for(int z=0; z<4; ++z) {
            int nx = cx + dx[z];
            int ny = cy + dy[z];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  //배열의 범위 초과인 경우 skip
                continue;
            
            if(board[nx][ny] == '0' && dist[nx][ny][cf] == -1) {
                dist[nx][ny][cf] = nextDist;
                q1.push({nx,ny,cf});
            }
            if(!cf && board[nx][ny] == '1' && dist[nx][ny][1] == -1 ) {
                dist[nx][ny][1] = nextDist;
                q1.push({nx,ny,1});
            }
        }
    }
    
    cout << answer;

    return 0;
}