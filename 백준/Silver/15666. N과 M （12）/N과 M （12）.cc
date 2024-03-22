#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//전형적인 백트래킹 문제이다.
//조금 특별한 점은 입력으로 들어오는 숫자들에 중복되는 숫자가 존재할 수 있다는 것과
//그와 동시에 중복으로 숫자를 선택해서 수열을 만들 수 있다는 점이다.
//그리고 각 수열은 비내림차순이어야한다.
//비내림차순을 구현하기 위해 num[]를 정렬할 것이며 여기서 반복되는 불필요한 작업을 제거하기 위해 
//중복된 숫자들을 제거하여 사용할 것이다.
//이때 조심해야될 것은 중복된 숫자들을 num[]에서 제거한 뒤에 num.size()에 맞게 n을 다시 초기화해줘야 된다는 것이다.
//안그러면 의도치 않은 Out of Index 문제가 생긴다.
//그리고 나는 비내림차순을 더 쉽게 구현하기 위해 arr[]에는 실제 값이 아닌 해당하는 num의 index를 담을 것이다.

int n,m;
int arr[8] = {0,};
vector<int> num;

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << num[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    int i=0;
    if(k>0)
        i = arr[k-1];
    
    for(; i<n; ++i) {
        arr[k] = i;
        recursive(k+1);
    }
}

int main(void) {
    int temp;
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());   //중복된 원소 제거
    n = num.size();
    recursive(0);
    
    return 0;
}