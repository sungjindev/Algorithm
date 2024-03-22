#include <iostream>
using namespace std;

//이번에는 Dynamic Programming 문제를 풀어보려고 한다.
//DP란 작은 단위로 문제를 쪼개서 Memorizing해두고 이를 활용해서 더 큰 문제를 점차적으로 해결해나가는 문제이다.

int d[1000001]; //DP를 위한 D 테이블

int main(void) {
    int n=0;
    cin >> n;
    d[1] = 0;
    
    for(int i=2; i<=n; ++i) {
        d[i] = d[i-1] + 1;
        if(i%2 == 0)
            d[i] = min(d[i], d[i/2] + 1);   //여기 반드시 min으로 비교해줘야함! 이유는 d[i/2]보다 d[i-1]이 더 작을 수 있다!!!
        if(i%3 == 0)
            d[i] = min(d[i], d[i/3] + 1);
    }
    cout << d[n];
}
