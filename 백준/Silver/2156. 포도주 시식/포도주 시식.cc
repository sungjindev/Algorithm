#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int num,n=0;
    int amount[10001] = {0, };
    int dp[10001] = {0,};
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> num;
        amount[i] = num;
    }
    
    dp[1] = amount[1];
    dp[2] = dp[1] + amount[2];
    
    for(int i=3; i<=n; i++) {
        dp[i] = max({dp[i-1], dp[i-2]+amount[i], dp[i-3]+amount[i-1]+amount[i]});
    }

    cout << dp[n];
    
    return 0;
}