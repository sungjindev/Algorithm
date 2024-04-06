#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

//이 문제는 전형적인 BFS 문제이다.
//조금 특이한 부분은 x,y,z 축을 가지는 3차원 모델이라는 것이다.
//따라서 나는 3차원 배열을 만들어서 풀이해줄 것이다.
//그 이외에는 크게 다를 것이 없다.

//visited 배열은 여러 테스트케이스에 대해 재활용해서 사용하므로 반드시 다시 초기화해주자.

char board[30][30][30];
int visited[30][30][30];

int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int l,r,c;
tuple<int,int,int> startPos;
tuple<int,int,int> endPos;

queue<tuple<int,int,int>> q1;   //x,y,z에 대한 좌표를 가지고 있어야 되므로 tuple을 사용

void bfs(void) {
    int x,y,z;
    tie(x,y,z) = startPos;
    
    visited[x][y][z] = 0;
    q1.push(startPos);
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        for(int i=0; i<6; ++i) {
            int nx = get<0>(curr) + dx[i];
            int ny = get<1>(curr) + dy[i];
            int nz = get<2>(curr) + dz[i];
            
            if(nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c || visited[nx][ny][nz] != -1 || board[nx][ny][nz] == '#')
                continue;
                
            visited[nx][ny][nz] = visited[get<0>(curr)][get<1>(curr)][get<2>(curr)] + 1;
            if(board[nx][ny][nz] == 'E') {    //종착지를 만난다면 큐를 모두 비운 다음 bfs 함수 종료
                while(!q1.empty())
                    q1.pop();
                return;
            }
            q1.push({nx,ny,nz});
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1) {
        cin >> l >> r >> c;
        if(!l && !r && !c)  //l,r,c가 모두 0이면 무한 루프 종료
            break;
        fill(&visited[0][0][0], &visited[29][29][30], -1);   //visited 배열을 재사용하기 위해 초기화
        
        for(int i=0; i<l; ++i) {
            for(int j=0; j<r; ++j) {
                for(int k=0; k<c; ++k) {
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S')   //입력을 받으면서 시작점과 종료점 좌표를 저장
                        startPos = {i,j,k};
                    else if(board[i][j][k] == 'E')
                        endPos = {i,j,k};
                }
            }
            cin.get(); //개행문자를 버려주기 위함
        }
        
        bfs();
        
        if(visited[get<0>(endPos)][get<1>(endPos)][get<2>(endPos)] != -1)
            cout << "Escaped in " << visited[get<0>(endPos)][get<1>(endPos)][get<2>(endPos)] << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
    
    return 0;
}