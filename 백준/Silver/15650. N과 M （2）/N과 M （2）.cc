#include <iostream>
using namespace std;

//이 문제 역시 이전 문제와 별반 다를 게 없는 백트래킹 문제이다.
//이전 문제에 오름 차순 정렬 내용이 추가되었다.
//따라서 백트래킹 핵심 로직에서 이 부분을 구현해주면 되는데, arr의 이전 인덱스 값보다 크다는 조건을 if문에 넣어주면 될 것 같다.

int n,m;

int arr[8];
bool isUsed[8];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
        if(!isUsed[i]) {
            if(k == 0) {    //이렇게 k == 0을 검사한 이유는 다음 if문의 조건인 arr[k-1]에서 Out of Index error를 피하기 위해
                arr[k] = i+1;
                isUsed[i] = true;
                func(k+1);
                isUsed[i] = false;
                continue;
            } 
            if(i+1 > arr[k-1]) {    //여기서 이전 arr 원소와 크기 비교를 해서 오름차순이 될 수 있도록 구현
                arr[k] = i+1;
                isUsed[i] = true;
                func(k+1);
                isUsed[i] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}