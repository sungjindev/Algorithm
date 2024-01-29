#include <iostream>
#include <list>
#include <queue>
using namespace std;

//빙하의 최대 개수는 10000개이다.
//100*100 정사각형 형으로 하면 바다에 접해있는 표면적을 줄여 worst case를 구할 수 있다.
//이러면 대각선에 존재하는 원소의 개수가 100개인데, 총 50개가 사라져야 가장 가운데 빙하들까지 모두 녹일 수 있다.
//굉장히 러프하게 구해서 바깥 1 Layer가 사라지는데 10년이 걸리므로 500년은 걸려야된다.

//우리가 관리해야되는 빙하의 최대가 10000개 이고 이들에 대해 500번 loop를 돌아 빙하의 녹는 것을 연산해줘야 하므로
//10000 * 500 = 5000000으로 충분히 시간 내 계산이 가능하다.

//원래는 보통 빙하만 따로 관리하지 않아도 시간 복잡도 내에 해결이 가능하지만,
//조금 더 시간복잡도를 줄이기 위해서 빙하만 따로 List(연결 리스트)로 관리하기로 결정하였다.
//연결 리스트를 사용하는 이유는 해당 리스트에서 현재 남아있는 빙하를 관리하기 위해 삽입, 삭제가 빈번하게 일어날 것이기 때문에
//O(1)로 삽입, 삭제가 가능한 연결 리스트를 사용한 것이다.

#define X first //pair를 조금 더 간결하게 쓰기 위해
#define Y second

int map[300][300];
int n,m,year;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
list<pair<int, int>> li1;   //빙하만 담아서 관리할 연결 리스트
bool visited[300][300];

void melting() {
    int afterMap[300][300];
    fill(&afterMap[0][0], &afterMap[299][300], 0);
    
    for(auto it = li1.begin(); it != li1.end(); ++it) {
        int x = (*it).X;
        int y = (*it).Y;
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 0)  //2차원 배열의 바운더리를 넘어가거나 빙하이면 skip
                continue;
                
            ++afterMap[x][y];   //녹여야되니까 1씩 증가
        }
    }

    for(auto it = li1.begin(); it != li1.end(); ++it) {
        int x = (*it).X;
        int y = (*it).Y;
        
        if(map[x][y] - afterMap[x][y] <= 0) {
            map[x][y] = 0;
            it = li1.erase(it);  //이제 빙하가 아니니까 연결 리스트에서 제거
            //위에서 항상 주의해야 될 것이 list에서 erase하면 해당 iterator의 위치의 원소를 지운다.
            //이걸 지운채로 해당 iterator를 그대로 사용하게되면 반드시 문제가 생길 수 밖에 없다.
            //왜냐하면 지워버려서 다음 원소로 가는 링크를 끊어 버렸고, 그 상태에서 for loop의 ++it를 거치게되면 다음이 없기 때문에 문제 발생
            //따라서 erase return 값을 이용해서 담아주자!!!
            //이렇게 담아주면 삭제한 원소의 다음 원소를 가리키는 iterator를 가리키게 된다.
            --it;   //그 iterator를 하나 줄여줌으로써 삭제되기 직전의 iterator를 문제 없이 가리킬 수 있게 된다.
            //이렇게하면 설령 가장 마지막 원소를 삭제해서 erase가 li1.end()를 가리킨다하더라도 그 직전 원소를 가리키기 때문에
            //문제가 생기지 않는다.
        } else {
            map[x][y] = map[x][y] - afterMap[x][y];
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q1;
    visited[x][y] = true;
    q1.push({x,y});
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        for(int i=0; i<4; ++i) {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0 || visited[nx][ny])  //2차원 배열의 바운더리를 넘어가거나 바다이거나 이미 방문했으면 skip
                continue;
                
            //이 아래는 빙하라는 의미이므로
            visited[nx][ny] = true;
            q1.push({nx,ny});
        }
    }
}

bool isOnlyOne() {
    if(!li1.size())
        return true;    //빙하가 다 녹은 상태면 그냥 true리턴해서 skip
        
    fill(&visited[0][0], &visited[299][300], false);    //bfs 돌리기 전에 초기화
    
    bfs(li1.front().X, li1.front().Y);  //빙하중 1개 뽑아서 걔를 시작점으로 bfs돌아서 한 덩어리인지 확인(한번에 모두 조회되는지 검사)
    
    for(auto it = li1.begin(); it != li1.end(); ++it) {
        int x = (*it).X;
        int y = (*it).Y;
        if(!visited[x][y])  //bfs를 돌렸지만 방문하지 않은 곳이 있다면 그건 한 덩어리가 아닌 것이다.
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) {    //초기 전체 지도 생성
        for(int j=0; j<m; ++j) {
            cin >> map[i][j];
            if(map[i][j] != 0)
                li1.push_back({i,j});   //빙하만 담기
        }
    }
    
    while(li1.size()) {
        melting();  //1년치 빙하 녹이기
        ++year;
        if(!isOnlyOne()) {   //한 덩어리인지 검사
            cout << year;
            return 0;
        }
    }
    
    cout << "0";
    return 0;
}