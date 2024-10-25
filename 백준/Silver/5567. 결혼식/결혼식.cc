#include <iostream>
#include <set>
#include <vector>
using namespace std;

//상근이의 친구와 상근이의 친구의 친구 명수를 찾는 것이다.
//그래프 문제이고, 겹지인이 존재할 수 있다.
//따라서 나는 우선 인접 리스트를 만든다음, 상근이의 학번인 1번과 친구인 번호들을 순회하면서
//상근이의 친구인 본인과 해당 번호의 친구들을 모두 set에 넣어 중복을 걸러줄 것이다.
//그 후 set의 개수를 조사해서 set에 1이 포함되어있으면 개수-1하고 1이 포함되어 있지 않으면 개수를 출력한다.
//set에서 1의 포함 여부는 s1.count()나 s1.find()로 찾으면 된다.

//하지만 더 쉽게 찾을 수 있는 방법은 초반에 상근이의 친구들을 조회할 때 친구가 없으면 결과값이 0이겠지만
//친구가 있다면 이후 친구 순회에서 무조건 1이 추가될 것이기 때문에 그냥 무조건 (set 개수-1)로 출력하면 된다.


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> adj[501];   //친구 관계를 저장할 인접 리스트   
    set<int> s1;    //중복 거르기 위해 만든 set
    
    int n,m,a,b;
    cin >> n >> m;
    
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    if(adj[1].size() == 0) {
        cout << "0";
        return 0;
    }
        
    for(auto friend1: adj[1]) {
        s1.insert(friend1);
        for(auto friend2: adj[friend1]) {
            s1.insert(friend2);
        }
    } 
 
    cout << s1.size()-1;   
    
    return 0;
}