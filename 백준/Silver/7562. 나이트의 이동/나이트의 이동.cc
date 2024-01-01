#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int visit[300][300];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 0;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int l,x,y,targetX,targetY;
        bool breakFlag = false;
        queue<pair<int,int>> q1;
        cin >> l;
        fill(&visit[0][0], &visit[l-1][l], -1);
        cin >> x >> y >> targetX >> targetY;
        visit[x][y] = 0;
        q1.push({x,y});
        while(!q1.empty()) {
            auto cur = q1.front();
            q1.pop();
            
            for(int j=0; j<8; ++j) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];

                if(nx < 0 || nx >= l || ny < 0 || ny >= l || visit[nx][ny] != -1)
                    continue;
                
                visit[nx][ny] = visit[cur.X][cur.Y] + 1;
                
                q1.push({nx, ny});
            }
        }

        cout << visit[targetX][targetY] << "\n";
    }
    return 0;
}