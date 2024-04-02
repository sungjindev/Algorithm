#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이 문제도 역시 직전 문제와 동일하게 상하좌우 인접한 요소들의 개수를 찾는 문제이다.
//DFS로 풀어도되고 BFS로 풀어도 된다.

//나는 DFS로 풀기로 결정했다.
//DFS를 위한 재귀 함수의 반환값에 해당 영역의 칸 수를 누적합해나가면 될 것이다.
//그리고 이 정보는 Vector에 저장하고 나중에 Vector를 오름차순 정렬해서 활용할 것이다.

#define X first
#define Y second

int n;
char board[25][25];
bool visited[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> areas;

int dfs(pair<int, int> pos) {
    int cnt = 1;
    
    for(int i=0; i<4; ++i) {
        int nx = pos.X + dx[i];
        int ny = pos.Y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == '0' || visited[nx][ny])
            continue;
        
        visited[nx][ny] = true;
        cnt += dfs({nx,ny});
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> board[i][j]; //한 줄에 공백없이 붙어서 입력이 들어오기 때문에 char형으로 저장
        }
    }
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(board[i][j] == '1' && !visited[i][j]) {
                visited[i][j] = true;
                areas.push_back(dfs({i,j}));
            }
        }
    }
    
    sort(areas.begin(), areas.end());

    cout << areas.size() << "\n";
    for(auto area: areas)
        cout << area << "\n";
    
    return 0;
}