#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

//sort 알고리즘의 cmp 비교 함수를 커스텀해서 풀었다.
//아래와 같이 튜플을 사용해서 금,은,동,팀이름을 묶어서 저장했고
//금,은,동 개수에 맞춰서 정렬했다.
//cmp 함수는 bool을 리턴하는 것이고 이게 true가 되게끔 정렬되는 로직이다.

bool cmp(tuple<int,int,int,int> a, tuple<int,int,int,int> b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            if(get<2>(a) == get<2>(b)) {
                return get<3>(a) > get<3>(b);
            }
            return get<2>(a) > get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,k,team,g,s,b;
    int kg,ks,kb;
    
    vector<tuple<int,int,int,int>> v1;
    cin >> n >> k;
    
    for(int i=0; i<n; ++i) {
        cin >> team >> g >> s >> b;
        if(team == k) { //찾아야되는 팀 K의 금은동은 저장! 왜냐하면 이 개수를 가지고 이따 등수를 찾을 것이기 때문이다.
            kg = g;
            ks = s;
            kb = b;
        }
        tuple<int,int,int,int> tuple1 = {g,s,b,team};
        v1.push_back(tuple1);
    }
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(int i=0; i<v1.size(); ++i) {    //정렬된 벡터를 조회하면서 금은동 개수가 찾아야하는 것과 같은지 비교하고 등수를 리턴했다.
        int q,w,e,r;
        tie(q,w,e,r) = v1[i];
        if(q==kg && w==ks && e == kb) {
            cout << i+1;
            return 0;
        }
    }
    
}