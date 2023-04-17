//x좌표에서 1번만 나온 좌표와 y좌표에서 1번만 나온 좌표가 정답이 되므로 Hash Map을 쓰고자 하였습니다.
//사실 데이터 양이 그렇게 많은 것이 아니라 Hash Map까지 쓸 필요는 없지만 연습할 겸 구현해봤습니다.
#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    //원래 일반적으로 변수를 선언하면 쓰레기 값이 들어가 있을 수도 있어서 반드시 초기화를 해주는 것이 좋지만,
    //map 같은 경우에는 기본적으로 비어있고 gcc compiler가 처음에 key 값을 넣으면 value를 0으로 초기화하므로 괜찮습니다.
    unordered_map<int,int> xMap;    //x좌표의 개수를 세어줄 xMap
    unordered_map<int,int> yMap;    //y좌표의 개수를 세어줄 yMap
    
    for(int i=0; i<3; i++) {
        int a,b;
        cin >> a >> b;
        
        xMap[a]++;
        yMap[b]++;
    }
    
    for(auto v: xMap) {
        if(v.second==1) {
            cout << v.first << " ";
        }
    }
    
    for(auto v: yMap) {
        if(v.second==1) {
            cout << v.first;
        }
    }
    
    return 0;
}