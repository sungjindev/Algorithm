#include <iostream>
#include <queue>
using namespace std;

//전형적인 BFS 문제이다.
//여기서 주의해야될 점은 불과 지훈이의 움직임에 대한 BFS를 동시에 돌려야 한다는 것이다.
//그리고 이 방문 기록, 비용에 대한 visited 배열을 지훈이와 불에 대해서 따로 둬야될 것 같다.
//간단히 말해 불을 먼저 BFS 다 돌린 뒤에 이어서 지훈이의 BFS를 돌린다.
//그러므로 이미 불이 몇초에 어디에 다녀갔는지 다 알 수 있으므로 그걸 바탕으로 지훈이가 갈 수 있는지 없는지 비교한다.

#define X first //Pair를 편리하기 위해 정의
#define Y second

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  fill(&dist1[0][0], &dist1[1001][1002], -1);
  fill(&dist2[0][0], &dist2[1001][1002], -1);
  for(int i = 0; i < n; i++)
    cin >> board[i];  
  queue<pair<int,int> > Q1;
  queue<pair<int,int> > Q2;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 'F'){
        Q1.push({i,j});
        dist1[i][j] = 0;        
      } else if(board[i][j] == 'J'){
        Q2.push({i,j});
        dist2[i][j] = 0;
      }
    }
  }
  // 불에 대한 BFS
  while(!Q1.empty()){
    auto cur = Q1.front(); Q1.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
      dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
      Q1.push({nx,ny});
    }
  }

  // 지훈이에 대한 BFS
  while(!Q2.empty()){
    auto cur = Q2.front(); Q2.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
        cout << dist2[cur.X][cur.Y]+1; 
        return 0;
      }
      if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; // 불이 이미 이전에 방문한 경우 불이 번진 것이므로 Skip!
      dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
      Q2.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미
  return 0;
}