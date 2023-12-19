#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

//전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.
//위와 같은 조건이 있으므로 모두 뒤집기 연산을 했다고 했을 때, 즉 70만 개의 배열 원소에 대해서 70만번 뒤집기 연산을 하면
//O(70만 * 70만)이므로 약 490000000000만의 연산으로 시간 초과에 걸리게된다.
//따라서 간단하게 Deque로 똑같이 시뮬레이션하여 구현할 수 없다.
//여기서 가장 시간 복잡도에 문제가 되는 것이 reverse()이므로 이 로직에서 시간을 벌어줘야되는데,
//boolean 변수 하나를 주어서 처음 deque에 모습과 동일한지 뒤집어져있는지를 구분하고
//이를 통해 실제로 뒤집진 않고 상태만 유지해주면 된다.
//이렇게하면 boolean 변수를 통해서 초기 상태와 다르게 뒤집어진 상태면 pop_back()을 해주면 되고 초기 상태와 같으면 pop_front() 해줄 수 있다.

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=0;
    cin>>t;
    
    for(int i=0; i<t; ++i) {
        string p="";
        string arrList="";
        stringstream ss1;
        int num = 0;
        int n=0;
        bool isError = false;
        bool isReversed = false;
        deque<int> dq1;
        cin >> p >> n >> arrList;
        
        for(auto& v: arrList) { //공백을 기준으로 stringstream이 토크나이징하므로 필요 없는 문자는 공백으로 만들기
            if(v < '0' || v > '9')
                v = ' ';
        }
        
        ss1.str(arrList);
        while(ss1 >> num) { //필요한 숫자만 파싱하여 덱에 저장
            dq1.push_back(num);
        }
        
        for(auto cmd: p) {
            if(cmd == 'R') {
                isReversed = !isReversed;
            } else if(cmd == 'D') {
                if(dq1.empty()) {
                    isError = true;
                    cout << "error\n";
                    break;
                } else {
                    if(isReversed)
                        dq1.pop_back();
                    else
                        dq1.pop_front();   
                }
            }
        }
        
        if(isError)
            continue;
            
        if(isReversed)
            reverse(dq1.begin(), dq1.end());
        
        cout << "[";
        for(auto it = dq1.begin(); it != dq1.end(); ++it) {
            if(++it == dq1.end()) {
                --it;
                cout << *it;
                break;
            }
            --it;
            cout << *it << ",";
        }
        cout << "]\n";
    }
    
    return 0;
}