#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int temp,n,k;
    vector<int> v1;
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    sort(v1.begin(), v1.end());
    
    cout << v1[k-1];
    
    return 0;
}