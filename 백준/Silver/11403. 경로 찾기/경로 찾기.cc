#include <iostream>
#include <vector>
using namespace std;

//이 문제는 주어진 인접 행렬을 바탕으로 모든 정점에서의 dfs를 수행하며
//visited 2차원 배열에 방문 가능 여부를 찍고 출력하는 문제이다.
//단 길이가 양수인 경로가 있어야 되므로, 일반적인 dfs와 다르게 첫 출발점은 visited로 찍으면 안된다.
//그리고 일반적인 visited랑 다르게 인접 행렬 기반으로 찍어야 되므로 출발점 행에대해서 도착점은 열로 치환하여 방문을 기록해야 한다.
//또한 각 정점에 대해 연결되어있는 여부를 인접 행렬에서는 모두 순회해야 하므로 조금 더 편리하게 인접 리스트로 변환하여 구하기로 했다.

vector<int> adj[101];
bool visited[101][101];

int n, a;

void dfs(int k, bool* arr) {
    for(auto v: adj[k]) {
        if(arr[v])
            continue;
        
        arr[v] = true;
        dfs(v, arr);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> a;
            if(a) {
                adj[i].push_back(j);    //인접 행렬을 인접 리스트로 변환하는 과정
            }
        }
    }
    
    for(int i=1; i<=n; ++i) {
        dfs(i, visited[i]); //dfs를 처음 시작한 정점 행에 대해 방문 여부를 기록해야 되서 해당 행에 대한 배열 주소를 넘겨준 것!
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}