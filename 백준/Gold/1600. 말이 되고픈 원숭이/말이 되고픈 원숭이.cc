#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

//일단 이 문제는 가능한 경로를 탐색하면서 최단 경로로 목표 지점에 도달하는 BFS 기반의 문제이다.
//근데 조금 특별한 점은 일반적인 상하좌우의 액션 뿐만 아니라 나이트와 같은 움직임이 있다는 것인데
//심지어 이 나이트와 같은 움직임의 횟수 제한이 그때그때 다 다르다.

//이전에 비슷한 문제를 풀면서 알게된 부분인데, 특정 시점마다 나이트가 몇번 남았는지에 따라서 cost를 계산하는 배열이
//따로 저장되어야 한다는 것이다.
//근데 그 문제는 고작 나이트와 같은 액션이 최대 1번까지라 1개만 만들던 visited 배열을 2개 만들어서 관리하면 되었지만
//이건 K가 최대 30이고 유동적으로 테스트 케이스마다 변하기 때문에 그렇게 하는 것은 비효율적이라는 생각이 들었다.
//그래서 나는 BFS queue에 넣을 때 그 상황에서 사용할 수 있는 나이트 잔여 횟수를 함께 넘겨서 구현할 것이다.

//참고로 이 문제에서 Board가 2차원 배열이므로 원래 일반적인 BFS 문제라면 Pair를 사용해서 2차원 배열의 각각의 인덱스를
//queue에 집어넣어줬겠지만, 나는 여기에 남은 나이트 횟수도 함께 넘겨줄 거기 때문에 tuple로 묶어서 queue에 넣어주기로 했다.

//여기서 또 중요한 부분이 나이트로 움직이면 속도가 빠르기 때문에 큐에 넣기 전에 필터링을 단순히 방문 여부로 하면 안된다.
//왜냐하면 queue에서 뒤에 위치한 애가 앞에보다 cost가 더 덜 들은채로 방문할 수도 있기 때문에
//cost가 더 작은지 여부를 보고 방문해야된다. 이를 위해 나는 visited 배열도 처음에 도달할 수 없는 MAX 값으로 초기화하였다.

//아니다!!!!!!!!
//위처럼 하면 안되는 반례가 있다.
//2
//10 2
//0 0 1 0 0 1 0 0 1 0
//0 0 1 1 0 0 0 0 1 0
//위에가 반례인데, 위처럼 그때그때 최소가 되는 cost에 따라 필터링을 해주면 cost를 줄이는데 급급해서 결국 끝에 도달하지 못하는
//경우가 생겨버린다.

//즉, k의 개수마다 따로 cost를 관리해줘야한다. 이는 visited 배열을 3차원 배열로 바꿔 visited[h][w][knight] 이런 식으로 구현하면 될 것이다.
//결론적으로, BFS queue에 잔여 나이트 횟수는 함께 tuple로 가져가야되면서, 필터링할 때도 단순히 나이트 잔여횟수 무관하게 최소 비용이면
//갱신할 것이 아니라, 나이트 잔여횟수 별로 나눠서 최소 비용이면 갱신하는 걸로 로직을 바꿔야 한다!!!!!!!
//이러기 위해선 위에서 말한 것처럼 visited[h][w][knight]로 바꿔야 한다!!!

#define MAX 999999

int dx1[4] = {1, 0, -1, 0};  //이건 일반적인 상하좌우에 대한 움직임
int dy1[4] = {0, 1, 0, -1};  //이건 일반적인 상하좌우에 대한 움직임

int dx2[8] = {2, 1, -1, -2, -2, -1, 1, 2};    //이건 나이트에 대한 움직임
int dy2[8] = {1, 2, 2, 1, -1, -2, -2, -1};    //이건 나이트에 대한 움직임

int board[200][200];
int visited[200][200][31];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, w, h;
    queue<tuple<int, int, int>> q1; //bfs를 위한 queue
    cin >> k >> w >> h;
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; ++j) {
            cin >> board[i][j]; //Board 만들기
        }
    }

    fill(&visited[0][0][0], &visited[199][199][31], MAX);   //-1로 visited 배열 초기화
    
    visited[0][0][k] = 0;
    q1.push(make_tuple(0, 0, k));   //배열의 인덱스와 남은 나이트 횟수를 tuple로 묶어서 queue에 넣기 
    
    while(!q1.empty()) {
        auto curr = q1.front();
        int currX, currY, currKnight;
        q1.pop();
        
        tie(currX, currY, currKnight) = curr;   //tuple을 각각의 변수로 풀어주기
        
        if(currKnight > 0) {
            for(int i=0; i<8; ++i) {    //나이트에 대한 움직임
                int nx = currX + dx2[i];
                int ny = currY + dy2[i];
                
                if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny][currKnight-1] <= visited[currX][currY][currKnight] +1 || board[nx][ny] == 1)  //이미 방문했거나 장애물이 있거나 적절한 인덱스 범위를 넘어가는 경우 skip!
                    continue;   //위 필터링 조건에서 주의해야될 점은 나이트 횟수에 따라 visited z축이 달라지기 때문에 나이트 횟수 1개 줄인 곳의 visited cost랑 비교해야됌!!!
                
                q1.push(make_tuple(nx, ny, currKnight-1));
                visited[nx][ny][currKnight-1] = visited[currX][currY][currKnight] + 1;
            }
        }

        for(int i=0; i<4; ++i) {    //일반적인 상하좌우에 대한 움직임
            int nx = currX + dx1[i];
            int ny = currY + dy1[i];
            
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny][currKnight] <= visited[currX][currY][currKnight] + 1  || board[nx][ny] == 1) //이미 방문했거나 장애물이 있거나 적절한 인덱스 범위를 넘어가는 경우 skip!
                continue;
                
            q1.push(make_tuple(nx, ny, currKnight));
            visited[nx][ny][currKnight] = visited[currX][currY][currKnight] + 1;
        }
        
    }
    int min = MAX;
    for(int i=0; i<=k; ++i) {
        if(min > visited[h-1][w-1][i])
            min = visited[h-1][w-1][i];
    }

    if(min == MAX)
        cout << "-1";
    else
        cout << min;
    
    return 0;
}