#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v1;
vector<vector<int>> check;
queue<pair<int,int>> q1;
int xpos[4] = {1,0,0,-1};
int ypos[4] = {0,1,-1,0};
int n,m;

void bfs(int a, int b) {
    check[a][b]=1;
    q1.push({a,b});

    while(!q1.empty()) {
        for(int i=0; i<4; i++) {
            int x = q1.front().first+xpos[i];
            int y = q1.front().second+ypos[i];
            
            if(x<0 || y<0 || x>=n || y>=m)
                continue;
            
            if(!check[x][y] && v1[x][y]) {
                q1.push({x,y});
                check[x][y]=check[x-xpos[i]][y-ypos[i]]+1;
            }
        }
        q1.pop();
    }
    
    cout << check[n-1][m-1];
}

int main(void) {
    string line;
    
    cin >> n >> m;
    v1 = vector<vector<int>>(n,vector<int>(m,0));
    check = vector<vector<int>>(n,vector<int>(m,0));
    
    for(int i=0; i<n; i++) {
        cin >> line;
        for(int j=0; j<line.size(); j++) {
            v1[i][j] = line[j]-'0';
        }
    }
    
    bfs(0,0);
    
    return 0;
}