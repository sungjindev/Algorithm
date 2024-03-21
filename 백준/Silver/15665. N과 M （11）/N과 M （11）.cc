#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이 문제가 이전 문제와 다른 점은 비오름차순이 아니어도 된다는 것. 
//그리고 같은 수를 여러번 골라도 된다는 점이다. 같은 수를 여러번 골라도 되기 때문에 isUsed[]같은 배열은 따로 선언해주지 않아도 된다.
//그리고 같은 수를 여러번 골라도 되기 때문에 처음에 num[] 배열을 입력받을 때 중복된 숫자들은 모두 제거해줘도 될 것 같다.
//이 부분은 sort 후에 unique와 erase를 활용해서 해줄 예정이고 이를 사용하기 위해 Vector로 num을 만들 것이다.

vector<int> num;
int arr[7] = {0,};
int n,m;

void recursive(int k) {
    if(k==m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; ++i) {
        arr[k] = num[i];
        recursive(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int number = 0;
    for(int i=0; i<n; ++i) {
        cin >> number;
        num.push_back(number);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());   //num Vector에서 중복된 원소 제거
    n = num.size(); //num Vector에서 중복을 제거해준 뒤 n 값을 삭제된 이후의 사이즈로 초기화해줘야 한다. 안그러면 엉뚱한 인덱스에 참조해버림
    recursive(0);
    return 0;
}