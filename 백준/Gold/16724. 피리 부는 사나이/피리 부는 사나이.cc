#include <iostream>
using namespace std;

//이번 문제는 처음에 바로 이해가 안되긴 했는데 결국은 이차원 배열을 그래프로 생각하고
//그 그래프 안에서 사이클의 개수를 찾는 문제입니다.
//왜냐하면, 문제에서 배열 밖으로 나가는 경우는 없다고 했기 때문에 결국은 사이클에 휘말리게 됩니다.
//그래서 저는 dfs를 활용해서 visited, finished 배열을 두고 Cycle이 있는지 검증할 것입니다.
//finished를 별도로 두는 이유는, 어떤 경로에 대해서 조회를 하고 있을 때 미처 해당 경로에 대한 조회가 끝나지 않았는데
//이미 방문한 노드를 방문하게 되면 그게 사이클이기 때문입니다.

char map[1000][1000];
bool visited[1000][1000];
bool finished[1000][1000];
int cycle;

void dfs(int i, int j) {
    visited[i][j] = true;
    
    int nextI = i;
    int nextJ = j;

    if(map[i][j] == 'U') {
        --nextI;
    } else if(map[i][j] == 'L') {
        --nextJ;
    } else if(map[i][j] == 'D') {
        ++nextI;
    } else if(map[i][j] == 'R') {
        ++nextJ;
    }
    
    if(!visited[nextI][nextJ]) {
        dfs(nextI, nextJ);
    } else if(!finished[nextI][nextJ]) {    //visited는 했는데, finished가 안됐다는 건 현재 조회 중인 경로에 이미 방문한 노드를 재방문 하고 있다는 것
    //따라서 이게 Cycle이다.
        ++cycle;
    }
    
    finished[i][j] = true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(!finished[i][j])
                dfs(i, j);
        }
    }
    
    cout << cycle;
    
    return 0;
}