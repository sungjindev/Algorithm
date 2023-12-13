#include <list>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int temp, n=0;
    list<pair<int, int>> l1;    //{풍선 번호, 풍선 안에 숫자} 꼴로 저장
    
    cin >> n;
    
    for(int i=1; i<=n; ++i) {
        cin >> temp;
        l1.push_back({i, temp});
    }
    
    auto next_target = l1.begin();
    
    while(l1.size()) {
        cout << (*next_target).first << " ";
        int cost = (*next_target).second;
        
        next_target = l1.erase(next_target);
    
        if (l1.empty()) {
            break;
        }
        
        if(cost<0){
            if(next_target == l1.begin()) { 
                next_target = l1.end();
            } 
            --next_target;
        } else {
            if(next_target == l1.end()) {
                next_target = l1.begin();
            }
        }
        
        for(int i=0; i<abs(cost)-1; ++i) {
            if(cost < 0) {
                if(next_target == l1.begin()) {
                    next_target = l1.end();
                }
                --next_target;
            } else {
                if(++next_target == l1.end()) {
                    next_target = l1.begin();
                }
            }
        }
    }
    
    return 0;
}