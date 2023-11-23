#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 핵심 알고리즘: deliveries와 pickups 중에서 먼저 back 쪽이 0이 되는 것들은 모두 제거한 상태로 사이즈를 비교해서 큰 사이즈가
// 가장 먼 거리에 가야만하는 곳이므로 해당 사이즈의 왕복 거리를 더해준다. 그리고 가장 먼 곳이므로 모든 거리의 delivery와 pickup 다녀올 수 있다. 그 중에서도 항상 가장 먼 곳 먼저 배달 및 수거를 진행하도록 하면 된다.

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(deliveries.size() != 0 || pickups.size() != 0) {
        int capa = cap;
        
        while(deliveries.size() != 0 && deliveries.back() == 0)
            deliveries.pop_back();
        
        while(pickups.size() != 0 && pickups.back() == 0)
            pickups.pop_back();

        if(deliveries.size() >= pickups.size()){
            answer += (deliveries.size()*2);
        } else {
            answer += (pickups.size()*2);
        }
            
        while(capa > 0) {
            if(!deliveries.size())
                break;
            
            if(deliveries.back() <= capa) {
                capa -= deliveries.back();
                deliveries.pop_back();
            } else {
                deliveries[deliveries.size()-1] -= capa;
                capa = 0;
            }
        } 
        capa = cap;
        while(capa > 0) {
            if(!pickups.size())
                break;
            
            if(pickups.back() <= capa) {
                capa -= pickups.back();
                pickups.pop_back();
            } else {
                pickups[pickups.size()-1] -= capa;
                capa = 0;
            }
        }            
        
    }
    
    return answer;
}