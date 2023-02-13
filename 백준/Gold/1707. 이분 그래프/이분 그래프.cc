#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v1;
int k,v,e;

void bfs(void) {
    vector<int> check(v,0);  //RED는 1, Black은 -1, 미방문은 0
    for(int i=1; i<=v; i++) {   //비연결 그래프에 대한 고려가 필요
        if(check[i-1] != 0)
            continue;
        int x=i;
        queue<int> q1;
        int mul = 1;
        q1.push(x);
        check[x-1] = mul;
        while(!q1.empty()) {
            x = q1.front();
            q1.pop();
            mul = check[x-1] * -1;
            for(int j=0; j<v1[x-1].size(); j++) {
                if(check[v1[x-1][j]-1] == mul*-1) {
                    cout << "NO" << "\n";
                    return;
                }
                if(check[v1[x-1][j]-1] == 0) {
                    q1.push(v1[x-1][j]);
                    check[v1[x-1][j]-1] = mul;   
                }
            }
        }
    }
    cout << "YES" << "\n";
}

int main(void) {
    int a,b;
    cin >> k;
    
    for(int i=0; i<k; i++) {
        cin >> v >> e;
        v1 = vector<vector<int>>(v,vector<int>());
        
        for(int j=0; j<e; j++) {
            cin >> a >> b;
            v1[a-1].push_back(b);
            v1[b-1].push_back(a);
        }
        bfs();
    }
    return 0;
}