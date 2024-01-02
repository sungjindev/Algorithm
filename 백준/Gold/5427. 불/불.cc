#include <iostream>
#include <queue>
using namespace std;

//상근이가 있는 위치도 당연히 불이 번질 수 있다.
//맵을 벗어나게 되면 탈출하는 것이다.
//가장 빠른 탈출시간을 구해야하므로, 방문했던 곳은 방문하면 안된다.
//먼저 불에 대한 BFS를 돌리면서 불의 전파에 대한 시간을 구한다.
//그 후, 상근이에 대한 BFS를 돌리면서 불이 이미 해당 시간에 전파된 것인지 여부에 따라 이동시킨다.

#define X first
#define Y second
#define MAX 99999999

char board[1000][1000];
int fireDist[1000][1000];
int sangguenDist[1000][1000];
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1,0,-1};
 
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=0;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int w,h;
        int answer = -1;
        bool breakFlag = false;
        queue<pair<int, int>> sangguenQ;
        queue<pair<int, int>> fireQ;
        cin >> w >> h;
        fill(&fireDist[0][0], &fireDist[h-1][w], MAX);
        fill(&sangguenDist[0][0], &sangguenDist[h-1][w], MAX);
        
        for(int j=0; j<h; ++j) {
            for(int k=0; k<w; ++k) {
                cin >> board[j][k];
                if(board[j][k] == '@') {
                    sangguenDist[j][k] = 0;
                    sangguenQ.push({j,k});
                } else if(board[j][k] == '*') {
                    fireDist[j][k] = 0;
                    fireQ.push({j,k});
                }
            } 
        }
        
        //여기서 부터 이제 불부터 BFS를 돌리기 시작한다.
        while(!fireQ.empty()) {
            auto cur = fireQ.front();
            fireQ.pop();
            
            for(int z=0; z<4; z++) {
                int nx = cur.X + dx[z];
                int ny = cur.Y + dy[z];
                
                if(nx < 0 || nx >= h || ny < 0 || ny >= w || fireDist[nx][ny] != MAX || board[nx][ny] == '#')
                    continue;
                
                fireDist[nx][ny] = fireDist[cur.X][cur.Y] + 1;
                fireQ.push({nx, ny});
            }
        }
        
        //이제 시간 별 불의 이동은 다 구했으므로, 상근이에 대한 BFS를 구하면 된다.
        while(!sangguenQ.empty()) {
            auto cur = sangguenQ.front();
            sangguenQ.pop();
            
            for(int z=0; z<4; z++) {
                int nx = cur.X + dx[z];
                int ny = cur.Y + dy[z];
                int ndist = sangguenDist[cur.X][cur.Y] + 1;
                
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    answer = sangguenDist[cur.X][cur.Y] + 1;
                    breakFlag = true;
                    break;
                }
                
                if(fireDist[nx][ny] <= ndist || sangguenDist[nx][ny] != MAX || board[nx][ny] == '#')
                    continue;
                
                sangguenDist[nx][ny] = ndist;
                sangguenQ.push({nx,ny});
            }
            
            if(breakFlag)
                break;
        }
        
        if(answer == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << answer << "\n";
    }    
    
    return 0;
}