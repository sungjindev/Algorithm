#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,temp, count=0;
    cin >> n >> m;
    vector<int> v1;
    
    for(int i=0; i<m; ++i) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    for(int i=0; i<v1.size(); ++i) {
        if(v1[i]==1) {
            --n;
            for(int j=i+1; j<v1.size(); ++j) {
                v1[j] = v1[j]-1 >= 1 ? v1[j]-1 : n;
            }
            continue;
        }
        
        if(v1[i]-1 < n-v1[i]+1) {
            count += v1[i]-1;
            for(int j=i+1; j<v1.size(); ++j) {
                v1[j] = v1[j]-(v1[i]-1) >= 1 ? v1[j]-(v1[i]-1) : n + v1[j]-(v1[i]-1);
                if(v1[j]-1==0) {
                    v1[j] = n-1;
                } else
                    --v1[j];
            }
        } else {
            count += n-v1[i]+1;
            for(int j=i+1; j<v1.size(); ++j) {
                if(v1[j]+(n-v1[i]+1) <= n) {
                    v1[j] = v1[j]+(n-v1[i]+1);
                } else {
                    v1[j] = v1[j]+(n-v1[i]+1)-n;
                }
                if(v1[j]-1==0) {
                    v1[j] = n-1;
                } else
                    --v1[j];
            }
        }
        --n;
    }
    
    cout << count;

    return 0;
}