#include <iostream>
using namespace std;

//이것도 역시 전형적인 백트래킹 문제이다.
//arr 배열에 가능한 숫자들을 모두 담고 (1부터 n까지)
//그리고 원래라면 isUsed 배열에 방문 여부를 bool 값으로 체크했겠지만, 이 문제는 숫자 중복이 가능하므로 체크하지 않는다.
//그리고 recursive() 함수를 통해 재귀적으로 호출하면서 백트래킹할 것이다.

int n,m;
int arr[7];

void recursive(int k) { //arr의 K번째 인덱스를 채우기 위한 함수
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
        arr[k] = i+1;
        recursive(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    recursive(0);
    return 0;
}