#include <iostream>
#include <algorithm>
using namespace std;

//이 문제도 전형적인 백트래킹 문제이다.
//하지만 조금 다른 점은 지금까지는 1부터 n 까지 연속적인 숫자들을 대상으로 순열을 만들어왔지만
//이번 문제에서는 순열을 구성하는 숫자들을 직접 입력받아야 된다는 것이 다르다.
//따라서 수열에 들어갈 숫자들이 들어있는 num 배열을 따로 만들어 줬다.
//그리고 순열 내 동일한 숫자 중복은 안되기에 isUsed 배열을 추가로 생성해야된다.

//근데 여기서 반드시 주의해야될 점이 수열은 사전순으로 증가하는 순서로 출력이 되어야하는데,
//num 배열에 값이 오름 차순으로 들어오는 것이 아니므로 한번 정렬시켜줘야 된다.
//정렬 시 주의할 것이 전체 배열 사이즈만큼 정렬하면 안되고 유의미한 숫자가 들어있는 n-1 인덱스까지만 정렬해야 된다.

int n,m;

int arr[8];
int num[8];
bool isUsed[8];

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
        if(!isUsed[i]) {
            arr[k] = num[i];
            isUsed[i] = true;
            recursive(k+1);
            isUsed[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> num[i];  //num 배열에 수열에 들어갈 숫자들을 입력 받는 로직
    }
    sort(&num[0], &num[n]); //정렬 시 주의할 것이 전체 배열 사이즈만큼 정렬하면 안되고 유의미한 숫자가 들어있는 n-1 인덱스까지만 정렬해야 된다.
    recursive(0);
    return 0;
}