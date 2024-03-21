#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
bool isUsed[8] = {0,};
int arr[8] = {0,};
int num[8] = {0,};

//이 문제는 이전 문제와 마찬가지로 수열에 들어갈 수 있는 후보 숫자들이 중복이 가능하다는 점이다.
//이점을 주의해서 잘 처리해줘야된다. 이 중복에 대해 고민하지 않으면, 추후 수열을 만들었을 때 동일한 수열이 여러번 출력되게 된다.
//이를 처리하기 위해서 나는 우선 num 배열을 정렬해서 사용할 것이고 정렬되어 있기 때문에 직접 수열을 만들 때 사용했던 값을
//temp 변수에 임시 저장했다가 비교할 것이다.

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << num[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    int i=0;
    int temp=0; //입력되는 숫자들은 모두 자연수이므로 0으로 초기화해도 괜찮다
    if(k > 0)   //비내림차순을 효율적으로 구현하기 위해
        i = arr[k-1]+1;
    
    for(;i<n;++i) {
        if(!isUsed[i] && temp != num[i]) {
            isUsed[i] = true;
            temp = num[i];
            arr[k] = i;
            recursive(k+1);
            isUsed[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;    
    for(int i=0; i<n; ++i) {
        cin >> num[i];
    }
    sort(num, num+n);
    recursive(0);
    return 0;
}