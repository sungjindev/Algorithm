#include <iostream>
using namespace std;

//상근이가 이기면 true, 창영이가 이기면 false로 저장한다고 가정
// dp[1] = true
// dp[2] = false
// dp[3] = true
// dp[4] = false
// dp[5] = true
// dp[6] = false

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    if(n%2==1)
        cout << "SK";
    else
        cout << "CY";
    
    return 0;
}