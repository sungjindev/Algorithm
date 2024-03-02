#include <iostream>
using namespace std;

//전형적인 하노이탑 문제이다.
//이는 재귀로 풀 수 있다. 1개의 원판을 3번째 기둥으로 옮길 수 있고. 2개의 원판이 있을 때도 3번째 기둥으로 옮길 수 있다.
//K개를 옮기면 K+1개도 옮길 수 있다. 즉 N개를 모두 재귀적으로 옮길 수 있다.

void hanoi(int start, int end, int n) { //원판이 n개가 있을 때 a에서 b로 옮기는 방법을 출력해주는 함수
    if(n==1) {
        cout << start << " " << end << "\n";
        return;
    }
    
    hanoi(start, 6-start-end, n-1);
    cout << start << " " << end << "\n";
    hanoi(6-start-end, end, n-1);
}

int main(void) {
    int n=0;
    cin >> n;
    
    cout << (1<<n)-1 << "\n";   //총 옮기는 횟수가 2^n-1 이므로 비트 연산자를 활용해서 계산!
    hanoi(1, 3, n);
    
    return 0;
}