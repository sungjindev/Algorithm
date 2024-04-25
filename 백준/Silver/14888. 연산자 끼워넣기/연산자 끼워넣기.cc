#include <iostream>
using namespace std;

//이 문제는 백트래킹으로 완전 탐색을 하면 풀기 쉬울 것이라고 생각되었다.
//전역적으로 현재 사용할 수 있는 각 연산자자들에 대한 횟수를 저장해놓고
//백트래킹 방식으로 1회 이상 남은 연산자들에 대해 연산을 모두 실행해보며 최대, 최솟값을 저장하도록 구현하면 될 것 같다.

//일단 숫자들의 후보는 num 배열에 저장한다. 최대 n은 11개이므로 size는 11로 설정한다.

int num[11];    //숫자들의 후보 저장
int operatorCnt[4]; //+,-,*,/ 순으로 남은 연산자 개수를 저장한다.
int mini = 1000000001;  //최솟값 저장
int maxi = -1000000001; //최댓값 저장
int n;

void func(int k, int sum) { //sum에는 현재까지의 누계, k는 현재 연산을 진행하고 있는 숫자의 인덱스를 나타냄. k는 0부터 시작
    if(k==n-1) {
        mini = sum < mini ? sum : mini;
        maxi = sum > maxi ? sum : maxi;
        return;
    }
    
    for(int i=0; i<4; ++i) {
        if(operatorCnt[i]) {
            --operatorCnt[i];
            if(i==0) {
                func(k+1, sum+num[k+1]);
            } else if(i==1) {
                func(k+1, sum-num[k+1]);
            } else if(i==2) {
                func(k+1, sum*num[k+1]);
            } else if(i==3) {
                func(k+1, sum/num[k+1]);
            }
            ++operatorCnt[i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> num[i];
    }
    
    for(int i=0; i<4; ++i) {
        cin >> operatorCnt[i];
    }
    func(0, num[0]);
    cout << maxi << "\n" << mini;
    return 0;
}