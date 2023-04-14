//BFS 문제이다. 
//dx,dy를 통해 동서남북 4방향을 표현하고 이걸 BFS를 이용해서 완전 탐색한다.
//BFS는 queue를 이용하도록 한다
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int visited[maps.size()][maps[0].size()];   //visited와 depth를 통합해서 관리하고자 함
    
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[0].size(); j++) {
            visited[i][j] = 0;
        }
    }

    queue<pair<int,int>> q1;
    
    pair<int,int> start = {0,0};
    visited[0][0] = 1;
    q1.push(start);
    
    while(!q1.empty()) {
        int fx = q1.front().first;
        int fy = q1.front().second;
        if(fx == maps.size()-1 && fy == maps[0].size()-1) {
            answer = visited[fx][fy];
            break;
        }
        
        for(int i=0; i<4; i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            
            if(nx >= 0 && nx <= maps.size()-1 && ny >= 0 && ny <= maps[0].size()-1) {   //행렬 경계값에 대한 예외 처리
                if(visited[nx][ny] == 0 && maps[nx][ny] == 1) { //방문을 안했고 길이 뚫려있을 때
                    q1.push({nx, ny});
                    visited[nx][ny] = visited[fx][fy]+1;
                }
            }
        }
        q1.pop();
    }
    
    if(q1.empty())
        answer = -1;
    
    return answer;
}