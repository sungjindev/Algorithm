//각 단계가 끝나면 제외된 사람의 다음 사람으로 이동해서 하나부터 외치게 된다!!!
//삽입 삭제가 잦은 시퀀스 컨테이너이므로 deque를 사용해보자!!!
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>    //pow를 써줄 것이므로 인클루드 해주자~
using namespace std;

int main(void) {
    int n=0;
    cin >> n;
    
    vector<int> dq1;
    for(int i=0; i<n; i++) {
        dq1.push_back(i+1); 
    }
    auto it = dq1.begin();

    for(int i=1; i<n; i++) {  //총 n-1 단계가 필요
        long long num = (((long long)pow(i,3))-1)%dq1.size();
        for(int j=0; j<num; j++) {
            it++;
            if(it == dq1.end())
                it = dq1.begin();
        }
        dq1.erase(it);
        if(it==dq1.end())
            it = dq1.begin();
    }
    
    cout << dq1[0];
    
    return 0;
}