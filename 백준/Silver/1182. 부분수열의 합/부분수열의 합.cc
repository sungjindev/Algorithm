#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,s,temp,count=0;
    vector<int> v1;
    cin >> n >> s;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    sort(v1.begin(),v1.end());
    
    
    for(int j=1; j<=n; j++) {
        vector<int> com(n-j,0);
        for(int z=0; z<j; z++)
            com.push_back(1);
    
        do {
            int sum = 0;
            for(int u=0; u<com.size(); u++) {
                if(com[u]==1) {
                    sum += v1[u];
                }
            }
            if(sum == s)
                count++;
        } while(next_permutation(com.begin(), com.end()));
    }
    
    cout << count;
    
    return 0;
}