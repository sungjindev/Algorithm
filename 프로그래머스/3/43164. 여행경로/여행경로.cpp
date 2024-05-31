#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//전형적인 dfs 문제이다.
//tickets를 적절히 그래프 형식으로 표현해서 ICN에서 출발하는 dfs를 돌리면 될 것 같다.
//근데 문제 요구 사항 중에서, 동일한 출발지에 대해 여러 경로가 있으면 알파벳 순서가 앞서는 대로 방문해야 된다고 했으므로
//나는 tickets를 활용해서 adj를 만들 때 map<string, priority_queue<string, vector<string>, greater<string>>> 형식으로 만들 것이다. 
//이렇게 하면 각 출발지를 key값으로 갖고 value에는 중복 없이 오름 차순 정렬되는 값들이 생기기 때문이다. 그리고 이미 사용한 티켓은 항상 top()에 있을텐데 제거하는데 코스트도 별로 안든다.

//아니다 위처럼 풀면 오답이다!!! 왜냐하면 위처럼하면 알파벳 순서대로 방문하는 건 지킬 수 있을 지 언정 그렇게 했을 때 모든 항공권을 이용하지 못할 수도 있다. 따라서 이건 백트래킹 방식으로 풀어야 된다. 알파벳 순으로 정렬된 상태에서 백트래킹을하고 모두 사용하는지 여부를 계속 체크해가면서 풀이해야 된다.
//우선 각 티켓 별로 map<string,set<pair<string,bool>>> 형식으로 저장하자. <출발지,vector<도착지,방문 여부>>이다.
//위처럼 set으로 하면 자동 오름차순 정렬까지 된다!
//그리고 백트래킹 하자! 

map<string,vector<pair<string,bool>>> visited;  //<출발지,set<도착지, 방문 여부>>를 나타내는 map
map<string,set<string>> adj;
string result[10000];  //백트래킹하면서 결과가 담길 배열
int n;
bool flag = false;

void back(int k) {
    if(k==n) {
        flag = true;
        return;
    }
    
    for(auto v: adj[result[k-1]]) {
        if(flag)
            break;
        
        for(auto& v2: visited[result[k-1]]) {
            if(v2.first == v && !v2.second) {
                result[k] = v;
                v2.second = true;
                back(k+1);
                v2.second = false;
            }
        }
            
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for(auto ticket: tickets) {
        visited[ticket[0]].push_back({ticket[1], false});
        adj[ticket[0]].insert(ticket[1]);
    }
    n = tickets.size()+1;
    
    result[0] = "ICN";
    back(1);
    
    for(int i=0; i<n; ++i)
        answer.push_back(result[i]);
    
    return answer;
}