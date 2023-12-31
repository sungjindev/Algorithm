#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//최소 일수를 구해야하므로, 이건 DFS 아니고 BFS로만 풀 수 있는 문제이다.
//m,n,h가 각각 최대 100까지 가능하므로 최대 부피는 1000000이다. 시간 초과는 걱정 없다.
//핵심 알고리즘은, 이 부피에 모든 익은 토마토를 시작점으로해서 Queue에 넣고 BFS를 돌린다. 
//그리고 Visit 배열을 일수를 계산하기 위하기 위해 누적합 개념으로 사용한다.
//Queue에 대한 루프가 돌 때, 남은 덜 익은 토마토 개수를 지속적으로 업데이트하여 종료 시점을 결정한다!
//이렇게 하지 않고 만약에 xyz 부피를 모두 조회하며 덜 익은 토마토가 있는지 확인한다면 굉장히 비효율적이다.
//결과적으로 Queue가 empty가 되면 루프를 빠져나와서 덜 익은 토마토 개수를 통해 덜 익은 토마토가 있는지 여부를 조회한다.
//여기서 주의해야될 문제 조건으로, 만약 처음부터 모두 토마토가 익어있는 상태면 0을 출력해야하고,
//토마토가 결국 모두 익지 못하는 상황이면 -1을 출력해야 한다.

int board[100][100][100];
int visit[100][100][100];   //0이면 방문하지 않은 것, 그 이외에는 1씩 증가시켜가며 익기 위한 최소 날짜 계산!

int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y,z,temp;
    int answer = 0;
    int unripeTomato = 0;
    queue<vector<int>> q1;
    
    cin >> x >> y >> z;
    
    for(int i=0; i<z; ++i) {
        for(int j=0; j<y; ++j) {
            for(int k=0; k<x; ++k) {
                cin >> board[k][j][i];
                if(board[k][j][i] == 0) {
                    ++unripeTomato; //초기값 입력 받을 때 덜 익은 토마토 개수 세기
                } else if(board[k][j][i] == 1) {
                    vector<int> v1 = {k, j, i};
                    q1.push(v1);
                    ++visit[k][j][i];
                }
            }
        }
    }
    
    if(unripeTomato == 0 ) {
        cout << "0";
        return 0;
    }
    
    while(!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        
        for(int i=0; i<6; ++i) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            int nz = cur[2] + dz[i];
            
            if(nx < 0 || nx >= x || ny < 0 || ny >= y || nz < 0 || nz >= z || (board[nx][ny][nz] != 0)) //배열 범위가 아니거나 익지 않은 토마토가 아니면 Skip
                continue;
            
            //그럼, 다음에 움직일 수 있는 위치가 익지 않은 토마토라면!
            --unripeTomato;
            board[nx][ny][nz] = 1;
            visit[nx][ny][nz] = visit[cur[0]][cur[1]][cur[2]] + 1;
            answer = visit[nx][ny][nz];
            
            vector<int> v1 = {nx, ny, nz};
            q1.push(v1);
            
        }
    }
    
    if(unripeTomato) {
        cout << -1;
    } else {
        cout << answer-1;
    }
    
    return 0;
}
