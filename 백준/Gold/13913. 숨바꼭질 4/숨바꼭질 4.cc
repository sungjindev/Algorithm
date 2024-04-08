#include <iostream>
#include <queue>
#include <deque>
using namespace std;

//이 문제는 전형적인 BFS 문제이다.
//특별한 조건이라면 2*x를 이동할 수 있는 순간 이동이 있다는 것이다.
//그리고 최단 시간을 찾을 뿐만 아니라 나중에 그 경로까지 출력해줘야 한다.

//이를 위해 이전 위치를 저장하는 배열 prePos를 만들 것이다.
//그리고 최단 경로 탐색이 완료되면 이 prePos를 역순으로 탐색해가며 역순으로 저장된 순서를 출력할 수 있다.

queue<int> q1;
int prePos[100001];
int visited[100001];

int subin, sister;

void bfs(void) {
    
    prePos[subin] = -1; //prePos의 시작점
    visited[subin] = 1;
    q1.push(subin);
    
    while(!q1.empty()) {
        int curr = q1.front();
        q1.pop();
        
        for(int nv: {2*curr, curr+1, curr-1}) {
            if(nv < 0 || nv >= 100001 || visited[nv])
                continue;
            
            prePos[nv] = curr;
            visited[nv] = visited[curr] + 1;
            q1.push(nv);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> subin >> sister;
    
    bfs();
    cout << visited[sister]-1 << "\n";

    deque<int> dq1 = {sister};
    
    while(dq1.front() != subin) {
        dq1.push_front(prePos[dq1.front()]);
    }
    
    for(int v: dq1)
        cout << v << " ";
    
    return 0;
}