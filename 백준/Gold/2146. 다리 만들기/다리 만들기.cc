#include <iostream>
#include <queue>
using namespace std;

//우선 지도의 최대 길이가 100이하로 주어지므로 최대 10000칸이다.
//생각한 알고리즘은 다음과 같다.

//우선 각 섬들을 구분하기 위해 전체 지도를 돌면서 섬마다 다르게 map에 islandNumber를 찍는다. 이때 전역 카운트 변수를 2부터 시작하도록 두고
//BFS를 활용해 한 섬에 대한 탐색이 끝나면 카운트 변수를 1 증가시켜 다음 방문하는 섬들에 대해서는 islandNumber에 3으로 찍는다.
//이 과정을 반복하여 모든 섬들에 대해 구분할 수 있는 값들을 map에 기록한다.

//이렇게 섬들이 모두 구분되었으면 다음은 다리의 길이를 탐색한다.
//마찬가지로 BFS를 활용하고 이건 전체 바다를 조회하는데 상하좌우에 섬이 있는 바다만 조회한다.
//상하좌우에 섬이있는 바다에 대해서 BFS를 돌리고 처음 시작한 바다 근처에 있는 섬의 번호와 다른 번호의 섬이 상하좌우에 처음 나타나면
//더이상 BFS 탐색을 하지 않고 해당 경로의 길이를 min 변수에 저장한다.
//그 후 이제 다른 상하좌우에 섬이있는 바다를 탐색하여 위와 같은 과정을 반복한다. 그럼 최종적으로 min에 담긴 변수가 정답이 된다.

//굉장히 rough하고 maxi하게 시간 복잡도를 계산해보면 최대 10000칸에 대해 서로 다른 칸들에 대한 조회 10000번씩 한다고하면,
//10000 * 10000 = 100000000이다. 이는 시간 제한 2초 안에 끝낼 수 있는 연산량이라 생각된다.

#define X first
#define Y second

int map[100][100];
int islandNumber = 2;
int n;
int minimum = 999999999;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[100][100];

void divideIsland(void) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(map[i][j] == 1) {
                queue<pair<int ,int>> q1;
                map[i][j] = islandNumber;
                q1.push({i,j});
                
                while(!q1.empty()) {
                    auto curr = q1.front();
                    q1.pop();
                    
                    for(int k=0; k<4; ++k) {
                        int nx = curr.X + dx[k];
                        int ny = curr.Y + dy[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] != 1)
                            continue;
                        
                        map[nx][ny] = islandNumber;
                        q1.push({nx, ny});
                    }
                }
                ++islandNumber;
            }
        }
    }
}

void makeBridge(void) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(map[i][j] == 0) {
                for(int k=0; k<4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 0)  //배열의 바운더리를 넘어가거나 섬이 아닌 경우 Skip
                        continue;
                    
                    bool breakFlag = false;
                    int currIslandNumber = map[nx][ny];
                    fill(&visited[0][0], &visited[n-1][n], 0);  //visited 배열을 재활용하기 위한 초기화
                    visited[i][j] = 0;
                    queue<pair<int ,int>> q1;
                    q1.push({i,j});
                    
                    while(!q1.empty() && !breakFlag) {
                        auto curr = q1.front();
                        q1.pop();
                        
                        for(int z=0; z<4; ++z) {
                            int nnx = curr.X + dx[z];
                            int nny = curr.Y + dy[z];
                            int nnc = visited[curr.X][curr.Y] + 1;
                            
                            if(nnx < 0 || nnx >= n || nny < 0 || nny >= n || map[nnx][nny] == currIslandNumber || visited[nnx][nny]) //시작 때 존재한 인근 섬과 같은 섬이면 skip
                                continue;
                            
                            if(map[nnx][nny] != 0) {
                                minimum = min(minimum, nnc);
                                breakFlag = true;
                                break;
                            }
                            
                            //0일 때는 이어서 BFS 탐색 진행 
                            visited[nnx][nny] = nnc;
                            q1.push({nnx, nny});
                        }
                    }
                    
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; ++i) {    //지도를 만드는 과정
        for (int j=0; j<n; ++j) {
            cin >> map[i][j];
        }
    }
    
    divideIsland(); //섬마다 구분하여 map에 표시해주기 위한 함수
    makeBridge();   //서로 다른 섬을 이어주는 다리를 만드는 과정
    
    cout << minimum;
    
    return 0;
}