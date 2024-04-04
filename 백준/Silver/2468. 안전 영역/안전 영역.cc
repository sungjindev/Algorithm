#include <iostream>
using namespace std;

//이 문제는 전형적인 DFS,BFS 완전 탐색(브루트 포스) 문제이다.
//DFS로 풀어도 되고 BFS로 풀어도 되지만 나는 DFS로 푸려고 한다.
//하나 특이한 점이라면 해수면의 높이를 다르게 바꿔가며 최대 높이값-1까지 물이 차는 것을 고려하여
//각각 DFS를 돌아줘야 한다.

//주의해야될 점으로 문제 힌트에 적혀있는 것처럼 아무 지역도 물에 잠기지 않을 수도 있다고 적혀있기 때문에
//아무리 못해도 결과값이 0이 아닌 1이 나와야한다는 것이다.

#define X first
#define Y second

int n;
int board[100][100];
bool visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int maxHeight;

void dfs(pair<int,int> pos, int rainfall) {    //탐색 좌표와 강수량을 매개 변수로 넘겨받는다
    for(int i=0; i<4; ++i) {
        int nx = pos.X + dx[i];
        int ny = pos.Y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] <= rainfall)
            continue;
            
        visited[nx][ny] = true;
        dfs({nx,ny}, rainfall);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 1;
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> board[i][j];
            maxHeight = maxHeight < board[i][j] ? board[i][j] : maxHeight;    //값을 입력받으면서 최대 높이를 구하는 것
        }
    }
    
    for(int i=1; i<maxHeight; ++i) {  //i가 0부터 시작이라면 비가 안오는 것인데 이에 대한 정답은 0이므로 1부터 시작하고 최대 높이까지 루프를 돌면 이에 대한 정답은 0이므로 최대 높이 -1까지 루프를 돈다
        int cnt=0;
        fill(&visited[0][0], &visited[n-1][n], false);  //visited 배열을 재사용하기 위해 초기화
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                if(board[j][k] > i && !visited[j][k]) {  //물에 침수되지 않은 지역이면서 방문하지 않은 곳에 대해 dfs
                    visited[j][k] = true;
                    dfs({j,k}, i); //탐색을 시작할 좌표와 현재 비가 내린 양을 같이 넘겨준다
                    ++cnt;
                }
            }
        }
        answer = answer < cnt ? cnt : answer;
    }
    cout << answer;
    return 0;
}