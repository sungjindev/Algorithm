#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

//이 문제는 전형적인 BFS 문제이다.
//문제 조건이 특이한데, 50미터 이동할 때마다 맥주를 마셔야 된다.
//그리고 이 맥주는 편의점에 들르게되면 20개로 다시 초기화된다.
//만약 맥주를 마셔야되는데 맥주가 없다면 해당 케이스는 더 이상 진행하면 안된다.
//그렇게 BFS를 돌아서 펜타포트 락 페스티벌에 도착하지 못하면 sad, 도착하면 happy를 출력하면 된다.

//하지만 만약 일반적인 BFS 문제처럼 거리 1만큼을 모두 2차원 배열 좌표계로 표현하려면 메모리 초과에 걸린다.
//왜냐하면 좌표의 범위가 32767*2+1=65535이므로 65535*65535 바이트는 약 4095메가바이트이기 때문이다.

//따라서 다르게 접근해야되는데, 50미터당 맥주 1병을 마셔야하고 최대 20개씩 가지고 다닐 수 있으므로
//쉽게 생각해서 1000m의 거리 차이까지 이동할 수 있다는 것이다. 
//즉 현 위치에서 종착점까지의 거리가 1000m 이내면 갈 수 있고, 만약 1000m보다 멀다면 무조건 편의점에 들려야 한다.
//물론 편의점까지 거리도 1000m 이내여야 한다.

#define X first
#define Y second

int t,n;

bool visited[100];  //편의점 방문 여부 체크
pair<int,int> store[100];   //편의점 좌표 저장
pair<int,int> home; //상근이 집 좌표
pair<int,int> festival; //페스티벌 좌표

bool bfs(void) {
    queue<pair<int,int>> q1;
    q1.push(home);
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        if(abs(curr.X-festival.X) + abs(curr.Y-festival.Y) <= 1000)
            return true;
        
        for(int i=0; i<n; ++i) {
            if(visited[i])
                continue;
            
            if(abs(curr.X-store[i].X) + abs(curr.Y-store[i].Y) <= 1000) {
                visited[i] = true;
                q1.push(store[i]);
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> t;
    
    while(t--) {
        int x,y;
        cin >> n >> x >> y;
        home = {x,y};
        for(int i=0; i<n; ++i) {
            cin >> x >> y;
            store[i] = {x,y};
        }
        cin >> x >> y;
        festival = {x,y};
        
        bool possible = bfs();
        if(possible)
            cout << "happy\n";
        else
            cout << "sad\n";
        
        fill(visited, visited+100, false);
    }
    
    return 0;
}