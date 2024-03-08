#include <iostream>
using namespace std;

//이 문제도 마찬가지로 백트래킹을 활용하는 문제인데
//앞선 문제들과 다른 점은 숫자의 중복이 가능하고 비내림차순이어야 한다는 것이다.
//이에 주의해서 재귀 함수 안에 조건문만 잘 짜주면 된다.
//중복은 가능하므로 isUsed 배열은 따로 만들 필요가 없다.

int n,m;
int arr[8];

void recursive(int k) { //k번째 index에 채울 숫자를 찾는 재귀 함수
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int j = 1;
    if(k>0) //k가 0일 경우, 즉 0번째 인덱스 숫자를 채울 경우에는 k-1 인덱스의 숫자가 없으므로 아래 for 문을 1부터 시작
        j = arr[k-1];
    for(;j<=n; ++j) {
        arr[k] = j;
        recursive(k+1);
    } 
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    recursive(0);
    return 0;
}