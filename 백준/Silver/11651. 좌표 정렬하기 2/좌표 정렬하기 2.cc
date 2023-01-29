#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second)
        return a.first < b.first;
        
    return a.second < b.second;    
}

int main(void) {
    vector<pair<int, int>> pos;
    int a,b,n=0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        pos.push_back({a,b});
    }
    
    sort(pos.begin(), pos.end(), cmp);
    
    for(auto i: pos)
        cout << i.first << " " << i.second << "\n";
    
    return 0;
}