#include <iostream>
#include <algorithm>
using namespace std;

//이 문제도 역시 전형적인 백트래킹 문제이다.
//이 문제에서는 수열을 만들 숫자들의 후보들을 num에 직접 입력 받아 사용하며 수열을 만들 때 동일한 숫자가 중복되어 사용되도 된다.
//따라서 사용 여부를 체크하는 isUsed[]와 같은 변수는 만들지 않아도 된다.
//여기서 주의해야 될 점은 수열을 사전 순으로 증가하는 순으로 출력해야 되기 때문에 num을 입력받고 정렬해서 사용해야 된다.

//참고로 아래에서 arr[]이 그때 그때 만들어진 수열을 담고 있을 배열인데 여기에 진짜 숫자값을 담지 않고 num[]의 index를 담아서
//유연성을 높였다. 이렇게 하면 혹시 나중에 수열 내 이전 수보다 큰 수로만 구성하도록 문제가 변경되었을 때도 쉽게 대응이 가능하다.

int num[7];
int arr[7];
int n,m;

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << num[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
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