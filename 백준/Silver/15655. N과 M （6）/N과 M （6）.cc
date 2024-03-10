#include <iostream>
#include <algorithm>
using namespace std;

//이 문제는 전형적인 백트래킹 문제이다.
//숫자 배열을 모두 직접 입력받고 이를 오름차순으로 중복없이 순열을 구하는 것이다.
//순열에 들어갈 수 있는 숫자 후보들은 num 배열에 저장하고
//isUsed를 통해 중복 여부를 확인하고 
//recursive()라는 재귀 함수를 정의해서 재귀적으로 호출하면서 arr에 순열들을 담아나갈 것이다.

int n,m;
int arr[8];
int num[8];
bool isUsed[8];

void recursive(int k) { //k번째 인덱스에 대한 arr 채우기 
    if(k == m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    for(int i=0; i<n; ++i) {
        if(k==0) {
            arr[k] = num[i];
            isUsed[i] = true;
            recursive(k+1);
            isUsed[i] = false;
        } else if(!isUsed[i] && arr[k-1] < num[i]) {
            arr[k] = num[i];
            isUsed[i] = true;
            recursive(k+1);
            isUsed[i] = false;
        }
    }
    
}

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> num[i];  //숫자의 후보들 채우기
    }
    
    sort(num, num+n);   //수열을 사전 순으로 증가하는 순으로 출력하기 위해 정렬
    recursive(0);
    
    return 0;
}