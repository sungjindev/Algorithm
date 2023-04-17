//꼭짓점의 개수를 점화식으로 표현할 수 있을 것 같아서 dynamic programming으로 풀이해봤습니다.
//한 변에 존재하는꼭짓점 갯수를 dp[]에 저장하고 이를 제곱하여 결과값을 출력하였습니다.
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n=0;
    vector<int> dp(16,0);
    dp[1] = 3;
    cin >> n;
    
    for(int i=2; i<=15; i++) {
        dp[i] = dp[i-1]+dp[i-1]-1;
    }
    
    cout << dp[n]*dp[n];
    
    return 0;
}