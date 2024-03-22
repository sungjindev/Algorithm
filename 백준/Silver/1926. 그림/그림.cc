#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//이 문제는 전형적인 그래프 탐색 문제이다. DFS와 BFS로 모두 풀이가 가능할 것 같다.
//나는 일단 BFS로 풀기로 했다.
//아 그런데 생각해보니까 BFS로 풀면 최단 경로가 보장되어서 그림의 크기를 구할 때 전체 1의 개수를 구하는 게 아니고
//최단 경로의 길이를 구해버려서 더 작은 값이 나온다. 물론 이건 아래 풀이처럼 pictureSize 변수를 둬서 여기에 카운팅해줘도 된다.

#define X first
#define Y second

int board[500][500];
int visited[500][500]; //여기에 cost도 같이 저장할 것이다.
queue<pair<int,int>> q1;    //BFS를 위한 queue이며 이차원 배열의 인덱스를 pair로 저장한다. 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int pictureNum = 0;
int n,m;

void bfs(void) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(visited[i][j] || !board[i][j])   //이미 방문한 곳이거나 지도상 0이면 Skip!
                continue;
            ++pictureNum;    //그림의 개수 1개 추가!
            int pictureSize = 1;    //이번 그림의 사이즈를 구하기
            visited[i][j] = 1;
            q1.push({i,j}); //BFS용 queue에 이차원 배열의 인덱스를 pair로 저장
            
            while(!q1.empty()) {
                auto curr = q1.front();
                q1.pop();   //사용하고 pop해주는 거 까먹지 말기
                
                for(int i=0; i<4; ++i) {
                    int nx = curr.X + dx[i];
                    int ny = curr.Y + dy[i];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || !board[nx][ny])   //배열의 범위를 넘어가거나 이미 방문한 곳은 skip!
                        continue;  //그리고 지도에서 0인 경우도 Skip!
                        
                    visited[nx][ny] = ++pictureSize;  //그림의 크기를 정하기 위함
                    q1.push({nx, ny});  //queue에 반드시 push 해주는 거 까먹지 말기
                }
            }
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j]; //지도 채우기
        }
    }
    
    bfs();
    cout << pictureNum << "\n";
    cout << *max_element(&visited[0][0], &visited[499][500]);
    
    return 0;
}