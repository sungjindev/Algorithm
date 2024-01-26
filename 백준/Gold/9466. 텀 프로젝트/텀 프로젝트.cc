#include <iostream>
using namespace std;

//문제에서 팀을 이루는 정의를 잘보면 그래프 상에서 Cycle이 돌면 팀이라는 것을 알 수 있다.
//따라서 문제에서 학생들을 그래프의 노드로 생각하고 간선을 연결해준 뒤 Cycle을 찾아내면 된다.
//전체 노드를 탐색하면서 자기로 돌아오는 Cycle이 있는지 검사한다.

//Cycle을 찾아내기 위해서 visited 배열과 finished 배열 이렇게 2개를 둔다.
//원래 보통 dfs, bfs 문제에서는 visited 배열 하나만 두고 푸는데, Cycle을 찾기 위해서는 finished 배열도 두어야 한다.
//왜냐하면, 탐색을 시작하면서 그래프를 도는데, 한번 탐색을 쭉 돌 때 그 안에서 visited는 했지만 아직 순회중인 경로에 포함된 node인 경우
//즉, 아직 탐색중인 경로에 포함된 노드이지만 이전에 방문했던 노드인 경우가 Cycle이기 때문에
//현재 탐색중인 경로에 포함되어있는지 여부를 알기 위해 finished 배열을 사용한다.
//그리고 사이클에 포함되어있는 노드의 개수를 쉽게 알기 위해 visited 배열을 단순 true/false 식의 flag 값으로 사용하지 않고
//몇번째로 방문한 노드인지를 기록하는 용도로 사용하여, 나중에 Cycle이 발견되면 "Cycle의 시작과 끝 노드 visited 값 차이 + 1"로
//Cycle 내 포함된 노드의 수를 쉽게 구할 수 있게 구현한다.

//dfs로 풀이하였다.

int nextNode[100001];   //다음 노드를 가르킨다. Array index 번호가 edge의 시작노드이고 nextNode[i]값이 edge의 종착노드이다.
int visited[100001];
bool finished[100001];
int nodeCountInCycle;   //Cycle에 포함되어있는 총 node의 개수
int orderNum;   //몇 번째로 방문한 노드인지 기억하기 위한 변수 0부터 시작

void dfs(int node) {
    visited[node] = orderNum++;

    if(visited[nextNode[node]] == -1)   //visited는 -1이 방문하지 않았다는 뜻
        dfs(nextNode[node]);
    else if(!finished[nextNode[node]])  //visited는 방문한 상태이면서, finished는 false라는 것은 
                                        //아직 순회중인 경로 내에 포함되어 있는 node인 경우라는 뜻. 즉 한 경로에 중복해서 방문하는 Cycle이라는 뜻
        nodeCountInCycle += (visited[node] - visited[nextNode[node]] + 1);
        
    finished[node] = true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        fill(&visited[0], &visited[n+1], -1);
        fill(&finished[0], &finished[n+1], false);
        nodeCountInCycle = 0;
        orderNum = 0;
        
        for(int i=1; i<=n; ++i) {
            cin >> nextNode[i];
        }
        
        for(int i=1; i<=n; ++i) {
            if(!finished[i]) {
                dfs(i);
            } 
        }
        
        cout << n - nodeCountInCycle << "\n";
    }
    
    return 0;
}