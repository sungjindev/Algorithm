#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.first == p2.first)
        return p1.second < p2.second;
    
    return p1.first < p2.first;
}

int main(void) {
    vector<pair<int,int>> pos;
    int a,b,n=0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        pos.push_back({a,b});
    }
    
    sort(pos.begin(), pos.end(), cmp);
    
    for(auto i: pos) {
        cout << i.first << " " << i.second << "\n";
    }
    
    return 0;
}