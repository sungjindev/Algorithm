#include <iostream>
#include <queue>
using namespace std;

//문제 자체는 그렇게 복잡하지가 않다. 일차원 좌표 상에서 두 점의 위치를 주고 한 점을 이동 시켜서 다른 점과 만나게할 수 있는 최단 시간을 찾는 문제
//수빈이가 5-10-9-18-17 순으로 가면 2초만에 동생을 찾을 수 있다.
//위 힌트를 보고 BFS가 떠올랐다. 우선 최단 경로(시간)이 보장되어야 하므로 당연히 DFS는 아니고 BFS로 탐색해야 된다는 생각이 들었다.
//이 BFS에 수빈이가 취할 수 있는 액션은 총 2가지이다. 하나는 시간(비용)이 들지 않는 2*x 순간이동이고,
//다른 하나는 1의 비용이 드는 -1 혹은 +1 좌표 이동이다.
//이 두가지 액션에 대해 모두 Queue에 넣어서 풀면 될 것 같다.

//근데 잘 생각해보면 여기서 주의해야될 점이 cost 관리이다.
//이 문제 같은 경우에는 비용이 안드는 경우가 포함되어 있어서 비슷한 타이밍에 Queue에대한 while루프를 돌지라도
//같은 인덱스에 대한 비용이 다 제각각일 수 있다.
//그래서 이런 문제를 막기 위해 Queue가 루프를 돌 때마다 teleport()를 호출시켜서 2의 거듭제곱에 해당하는 모든 인덱스에 미리 Cost를 채워놓으면 된다.
//그러면 동일한 비용이 드는 +1, -1, 텔레포트 액션에 대해 동시에 queue에 넣을 수 있게 되어서 일반적인 BFS처럼
//Queue 루프에 따라 최소 비용이 보장된다.

#define LIMIT 100001

int board[LIMIT] = {0, };
queue<int> q1;    
int n,k;

void teleport(int num) {
    int temp = num;
    
    if(!temp)    //여기서 주의할 점이 만약에 0이 들어와버리면 무한 루프에 빠져버리므로 이 예외처리를 반드시 해줘야 시간초과에 안걸린다!!!
        return;
    
    while(temp < LIMIT && !board[k]) {
        if(!board[temp]) {  //Queue 루프가 최소 비용이 보장되므로 이미 방문한 곳이라면 더 비싼거나 같은 비용이 들 수 밖에 없음
            board[temp] = board[num];
            q1.push(temp);
            
            if(temp == k)   //동생을 만난 것이므로 return
                return;
        }
        temp <<= 1; //LEFT SHIFT 비트 연산자를 이용해 2배를 해준 것
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    board[n] = 1;   //여기서 비용이드는 액션을 하지 않았음에도 방문 표시를 위해 바로 1로 체크했으니 추후 cost는 -1하여 출력해줘야 한다.
    q1.push(n);
    teleport(n);    //n에 대해 텔레포트를 모두 다 실행! 왜냐하면 이때 비용이 같으므로
    
    while(!board[k]) {  //while 루프 조건문에 동생을 만난 경우를 탈출 조건으로 설정
        int curr = q1.front();
        q1.pop();
        
        vector<int> nvList = {curr-1, curr+1};
        
        for(int nv: nvList) {
            if(nv < 0 || nv >= LIMIT || board[nv])
                continue;
                
            board[nv] = board[curr] + 1;
            q1.push(nv);
            teleport(nv);
        }
    }
    
    cout << board[k] -1;
    
    return 0;
}