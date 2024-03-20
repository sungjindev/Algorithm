#include <iostream>
#include <algorithm>
using namespace std;

//이 문제는 역시 이전 문제와 동일하게 전형적인 백트래킹 문제이다.
//수열에 들어갈 수 있는 숫자들 역시 직접 입력받고
//수열을 구성할 때 사전 상 증가하는 순서로 출력해야 한다.

int n,m;
bool isUsed[8] = {0,};
int arr[8] = {0, };
int num[8] = {0, }; 

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << num[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    int temp = 0;   //이전 수열에서의 k번째 항이 같은 숫자인지 비교해주는 것!!!
    //여기서 주의해야될 점은 이게 같은 수열에서의 중복을 거르는 게 아니라는 것이다!!! 그래서 문제 조건에 맞는 것이다.
    //문제 조건에 따르면 한 수열안에 동일한 숫자가 들어갈 수 있다.
    for(int i=0; i<n; ++i) {
        if(!isUsed[i] && temp != num[i]) {
            isUsed[i] = true;
            arr[k] = i;
            temp = num[arr[k]];
            recursive(k+1);
            isUsed[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> num[i];
    }
    sort(num, num+n);
    recursive(0);
    return 0;
}