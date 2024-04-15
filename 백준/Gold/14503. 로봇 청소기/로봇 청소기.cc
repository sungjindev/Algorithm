#include <iostream>
#include <queue>
using namespace std;

//이 문제는 시뮬레이션 문제이고 BFS로 풀이가 가능할 것 같다.
//주어진 요구사항(조건)에 맞게 잘 구현하면 된다.

#define X first
#define Y second

int board[50][50];
bool visited[50][50];
int n,m,r,c,d,answer;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(void) {
    queue<pair<int,int>> q1;
    visited[r][c] = true;
    ++answer;
    q1.push({r,c});
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        bool isCleanedBlank = false;
        
        for(int i=0; i<4; ++i) {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny])
                continue;
            
            isCleanedBlank = true;  //사방 중 청소되지 않은 빈칸이 존재한다는 뜻이다.
            break;
        }
        
        if(!isCleanedBlank) {
            int nx,ny;
            if(d==0) {
                nx = curr.X + 1;
                ny = curr.Y;
            } else if(d==1) {
                nx = curr.X;
                ny = curr.Y - 1;
            } else if(d==2) {
                nx = curr.X - 1;
                ny = curr.Y;
            } else if(d==3) {
                nx = curr.X;
                ny = curr.Y + 1;
            }
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny])
                return;
            
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                ++answer;
            }
            q1.push({nx,ny});
        } else {
            int nx,ny;
            do {
                if(d==0)
                    d = 3;
                else
                    --d;
                
                if(d==0) {
                    nx = curr.X - 1;
                    ny = curr.Y;
                } else if(d==1) {
                    nx = curr.X;
                    ny = curr.Y + 1;
                } else if(d==2) {
                    nx = curr.X + 1;
                    ny = curr.Y;
                } else if(d==3) {
                    nx = curr.X;
                    ny = curr.Y - 1;
                }
            
            } while(visited[nx][ny] || board[nx][ny]);
            
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            ++answer;
            q1.push({nx,ny});
        }
        
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c >> d;
    
    for(int i=0;  i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> board[i][j];
        }
    }
    
    bfs();
    cout << answer;
    return 0;
}