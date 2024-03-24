#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

//이 문제는 고정된 5*5 이차원 배열에서 총 7명을 뽑아 BFS로 인접한 학생들로만 구성되어 있는 경우에 대해
//완전 탐색하면서 이다솜파가 4명 이상인지 검사하면 된다.

//따라서 나는 25명 중 7명을 뽑기 위해 next_permutation()을 활용한 조합을 사용하기로 결정했고
//그 각각의 조합 케이스에 대해 BFS를 돌며 서로 상하좌우로 인접해있는지 검사하고 그렇게 7명이 선택되면
//그때 이다솜파가 4명 이상인지 검사할 것이다.

//여기서 참고로 주의해야될 점이 입력이 띄워쓰기로 제공되지 않는다는 점이다.
//따라서 나는 String 형태의 배열로 입력을 받아 사용하기로 했다.

#define X first //pair를 조금 더 편하게 쓰기 위해
#define Y second

string board[5];
bool mask[25];  //조합 계산용 Mask array이다. 여기에 7개만큼 false을 채워넣을 것이고 그 뒤로는 true로 채울 것이다. 그리고 0이 있는 자리가 조합의 구성 인덱스이다.

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0; //정답 개수
    for(int i=0; i<5; ++i) {
        cin >> board[i];
    }    
    
    fill(mask+7, mask+25, true);
    
    do {
        queue<pair<int, int>> q1;   //BFS를 위한 queue
        bool is7member[5][5] = {false,};    //7인에 해당하는지, 즉 현재 조합의 경우에 포함되는지 표시하기 위함
        bool visited[5][5] = {false,};  //방문 여부를 표시하기 위함
        int memberCount = 0;    //현재 조합의 경우에서 현재까지 총 방문한 사람 수
        int dasomCount = 0;     //그 중에서 다솜파의 수
        
        for(int i=0; i<25; ++i) {
            int x = i/5;    //행을 계산하기 위함
            int y = i%5;    //열을 계산하기 위함
            
            if(!mask[i]) {   //현재 조합의 경우의수에 포함되는 경우
                is7member[x][y] = true;
                
                if(q1.empty()) {    //모든 배열의 원소를 돌면서 조합에 포함되는 인덱스를 한번에 queue에 넣을 필요 없이 1개만 넣으면 되므로!
                    visited[x][y] = true;
                    q1.push({x,y});
                }
            }
        }
        
        while(!q1.empty()) {
            auto curr = q1.front();
            q1.pop();
            ++memberCount;
            dasomCount += board[curr.X][curr.Y] == 'S'; //다솜파이면 카운트 1 증가, 아니면 0 증가
            
            for(int i=0; i<4; ++i) {
                int nx = curr.X + dx[i];
                int ny = curr.Y + dy[i];
                
                if(nx<0 || nx >=5 || ny<0 || ny>=5 || visited[nx][ny] || !is7member[nx][ny])
                    continue;
                
                visited[nx][ny] = true;
                q1.push({nx,ny});
            }
        }
        
        answer += (memberCount == 7 && dasomCount >= 4);    //memberCount가 7이면서 그 중 다솜파가 4명이상인 경우 1 증가, 아니면 0 증가
    } while(next_permutation(mask, mask+25));
        
    cout << answer;
    return 0;
}