#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int temp,max,n=0;
    vector<int> price(1,0);
    vector<int> dp(1,0);
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> temp;
        price.push_back(temp);
    }
    
    dp.push_back(price[1]);
    
    for(int j=2; j<=n; j++) {
        max = 0;
        for(int z=1; z<=j/2; z++) {
            if(max < dp[z]+dp[j-z])
                max = dp[z]+dp[j-z];
        }
        if(max < price[j]) 
            dp.push_back(price[j]);
        else 
            dp.push_back(max);
    }
    
    cout << dp[n];
    
    return 0;
}