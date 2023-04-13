//최단 경로를 구해야하므로 BFS이다!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000001

int visited[MAX] = {0,};

int main(void) {
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    queue<int> q1;
    q1.push(s);
    visited[s] = 0;
    
    
    while(!q1.empty()) {
        if(q1.front() == g) {
            break;
        } else {
            if(q1.front()+u <= f) {
                if(!visited[q1.front()+u] && q1.front()+u != s) {
                    q1.push(q1.front()+u);
                    visited[q1.front()+u] = visited[q1.front()]+1;
                }
            }
            if(q1.front()-d >= 1) {
                if(!visited[q1.front()-d] && q1.front()-d != s) {
                    q1.push(q1.front()-d);
                    visited[q1.front()-d] = visited[q1.front()]+1;
                }
            }
        }
        q1.pop();
    }
    
    if(!q1.empty())
        cout << visited[g];
    else
        cout << "use the stairs";
    
    return 0;
}