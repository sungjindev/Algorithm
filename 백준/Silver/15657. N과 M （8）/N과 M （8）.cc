#include <iostream>
#include <algorithm>
using namespace std;

//이 문제도 전형적인 백트래킹 문제이다.
//수열에 들어갈 숫자들을 num 배열에 직접 입력받고
//수열내 중복이 가능하며 수열은 비내림차순이어야 한다.
//중복이 가능하기 때문에 isUsed 배열은 사용하지 않을 것이며
//오름 차순으로 정렬해야 되므로 num 배열에 후보 숫자들을 입력받고 정렬한 뒤 사용할 것이다.
//그리고 정렬된 num 배열에서 이전 수보다 더 큰거나 같은 수를 쉽게 찾기 위해 수열 관련 정보를 저장하는 arr 배열에는 
//숫자를 직접 담지 않고 num 배열 상의 index를 담을 것이다.

int n,m;
int num[8];
int arr[8];

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << num[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    int i = 0;
    if(k!=0) {
        i = arr[k-1];
    }
    
    for(; i<n; ++i) {
        arr[k] = i;
        recursive(k+1);
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