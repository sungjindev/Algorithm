#include <iostream>
#include <queue>
using namespace std;

//일단 방문하지 않은 곳은 n*n 배열 순회하면서 모두 시작점으로 탐색
//그리고 이걸 적록색약인 사람과 아닌 사람에 대한 케이스로 나눠 변수를 따로 저장하여 계산
//board는 공유해서 사용

#define X first //pair를 편리하게 사용하기 위해 지정
#define Y second    //pair를 편리하게 사용하기 위해 지정

char board[100][100];
bool visitNormal[100][100]; //적록색약이 아닌 사람
bool visitAbnormal[100][100];   //적록색약인 사람

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n=0;
    int answerNormal = 0;
    int answerAbnormal = 0;
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            queue<pair<int, int>> q1;
            //적록색약이 아닌 사람
            if(!visitNormal[i][j]) {
                visitNormal[i][j] = true;
                q1.push({i, j});
                ++answerNormal;
                
                while(!q1.empty()) {
                    auto cur = q1.front();
                    q1.pop();
                    
                    for(int k=0; k<4; ++k) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visitNormal[nx][ny] || (board[cur.X][cur.Y] != board[nx][ny]))
                            continue;
                        
                        visitNormal[nx][ny] = true;
                        q1.push({nx, ny});
                    }
                }
            }
            
            //적록색약인 사람
            if(!visitAbnormal[i][j]) {
                visitAbnormal[i][j] = true;
                q1.push({i, j});
                ++answerAbnormal;
                
                while(!q1.empty()) {
                    auto cur = q1.front();
                    q1.pop();
                    
                    for(int k=0; k<4; ++k) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visitAbnormal[nx][ny])
                            continue;
                            
                        if(board[cur.X][cur.Y] == 'B') {
                            if(board[nx][ny] != 'B')
                                continue;
                        } else {
                            if(board[nx][ny] == 'B')
                                continue;
                        }
                        
                        visitAbnormal[nx][ny] = true;
                        q1.push({nx, ny});
                    }
                }
            }
        }
    }
    
    cout << answerNormal << " " << answerAbnormal;
    
    return 0;
}