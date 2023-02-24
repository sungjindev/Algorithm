#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int,int>> q1;
vector<int> visited(100001,0);
int n,k;
int result = 0;

void bfs(void) {
    q1.push({n,0});
    visited[n]++;
    while(!q1.empty()) {
        int x = q1.front().first;
        int cnt = q1.front().second;
        
        if(x == k) {
            cout << cnt;
            break;
        }
        
        if(x-1 >= 0 && x-1 < 100001) {
            if(!visited[x-1]) {
                q1.push({x-1, cnt+1});
                visited[x-1]++; 
            }
        }
        if(x+1 >= 0 && x+1 <= 100000) {
            if(!visited[x+1]) {
                q1.push({x+1, cnt+1});
                visited[x+1]++;
            }
        }
        if(x*2 >= 0 && x*2 <= 100000) {
            if(!visited[x*2]) {
                q1.push({x*2, cnt+1});
                visited[x*2]++;
            }
        }
        q1.pop();
    }
}

int main(void) {
    cin >> n >> k;

    bfs();
    
    return 0;
}