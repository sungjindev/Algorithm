#include <iostream>
using namespace std;

//이 문제는 전형적인 Dynamic programming 문제로, Memorization을 이용해서 풀면 된다.

int dp[46];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[1] = 1;
    
    int n;
    cin >> n;
    
    for(int i=2; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n];
    
    return 0;
}