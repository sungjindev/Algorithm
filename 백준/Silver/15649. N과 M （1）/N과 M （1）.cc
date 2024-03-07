#include <iostream>
using namespace std;

int n,m;
int arr[8];
bool isUsed[8];

//이 문제는 전형적인 백트래킹 문제이다.
//나는 인덱스 0부터 시작하도록 문제를 풀었다.
//func() 함수를 재귀적으로 호출하면서 해결해주면 되고, 재귀적으로 호출한 다음, 해당 인덱스에 대한 사용 여부를 다시 false로 바꿔주는 게 핵심

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
        if(!isUsed[i]) {
            arr[k] = i+1;
            isUsed[i] = true;
            func(k+1);
            isUsed[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;
    func(0);
    return 0;
}