#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,m,k,temp;
    long long mini, cost=0;
    long long sum1 = 0;
    long long sum2 = 0;
    vector<long long> storage1;
    vector<long long> storage2;

    
    cin >> n >> m >> k;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        sum1 += temp;
        storage1.push_back(temp);
    }
    
    for(int i=0; i<m; i++) {
        cin >> temp;
        sum2 += temp;
        storage2.push_back(temp);
    }
    
    mini = min(sum1,sum2);
    sum1 = mini;
    sum2 = mini;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<storage1[i] && sum1 > 0; j++) {
            --sum1;
            cost += i+1;
        }
        if(sum1<=0)
            break;
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<storage2[i] && sum2 > 0; j++) {
            --sum2;
            cost += i+1;
        }
        if(sum2<=0)
            break;
    }

    cout << mini << " " << cost;
    
    return 0;
}