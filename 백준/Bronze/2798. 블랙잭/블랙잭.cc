#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,m,temp;
    int sum = 0;
    vector<int> vInput;
    cin >> n >> m;
    vector<int> v1(n);
    for(auto z=v1.end()-1; z != v1.end()-4; --z) {
        *z = 1;
    }
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        vInput.push_back(temp);
    }
    
    sort(vInput.begin(), vInput.end());
    
    do {
        int afterSum = 0;
        
        for(auto u=v1.begin(); u<v1.end(); u++) {
            if(*u == 1)
                afterSum += vInput[u-v1.begin()];
        }
        
        if(afterSum <= m && afterSum > sum)
            sum = afterSum;
            
    } while(next_permutation(v1.begin(), v1.end()));
    
    cout << sum;
    
    return 0;
}