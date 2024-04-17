#include <iostream>
using namespace std;

//이 문제는 쉽게 말하면 조합에 관한 문제이다.
//특히 이 문제는 백트래킹을 통해 해결하면 쉽게 풀 수 있다.
//아니면 next_permutation을 활용하여 조합을 구해 풀어도 된다.

int n,s,cnt;
int arr[20];

void func(int curr, int total) {
    if(curr == n) {
        if(total == s)
            ++cnt;
        return;
    }
    
    func(curr+1, total);
    func(curr+1, total + arr[curr]);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    
    func(0,0);
    if(s==0)    //크기가 양수인 부분 수열이므로 공수열(?)은 빼줘야 된다
        cout << cnt-1;
    else
        cout << cnt;
    
    return 0;
}