#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//가변 배열인 vector를 이용해서 시뮬레이션을 하기로 했다.
//그리고 target 값인 num보다 큰 수 중에 가장 작은 수를 찾기 위해 upper_bound()를 사용했다.
//만약 그러한 수가 없다면 upper_bound()의 반환값이 v1.end() 일 것이므로 이걸로 분기를 했다.
//그러한 수가 존재한다면 해당 위치부터 끝까지는 뒤로 한칸씩 이동해줘야 되므로 계산해서 answer에 누적합해줬다.

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p,t,num;
    cin >> p;
    
    while(p--) {
        vector<int> v1;
        int answer = 0;
        cin >> t;
        for(int i=0; i<20; ++i) {
            cin >> num;
            vector<int>::iterator iter = upper_bound(v1.begin(), v1.end(), num);
            if(iter==v1.end()) {
                v1.push_back(num);
            } else {
                answer = answer + v1.size()-(iter-v1.begin());
                v1.insert(iter, num);
            }
        }
        cout << t << " " << answer << "\n";
    }
    
    return 0;
}