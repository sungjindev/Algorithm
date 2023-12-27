#include <iostream>
#include <queue>
using namespace std;

#define X first 
#define Y second

int board[50][50];
bool visit[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t,m,n,k;
    cin >> t;
    
    for(int i=0; i<t; ++i) {
        int answer = 0;
        queue<pair<int, int>> q1;
        cin >> m >> n >> k;
        fill(&board[0][0], &board[m-1][n], 0);
        fill(&visit[0][0], &visit[m-1][n], 0);
        for(int j=0; j<k; ++j) {
            int a,b;
            cin >> a >> b;
            board[a][b] = 1;
        }

        for(int x=0; x<m; ++x) {
            for(int y=0; y<n; ++y) {
                if(!board[x][y] || visit[x][y])
                    continue;
                
                visit[x][y] = true;
                q1.push({x,y});
                answer++;
                
                while(!q1.empty()) {
                    auto cur = q1.front();
                    
                    for(int k=0; k<4; ++k) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n || visit[nx][ny] || !board[nx][ny])
                            continue;
                        
                        visit[nx][ny] = true;
                        q1.push({nx, ny});
                    }
                    q1.pop();
                }
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}