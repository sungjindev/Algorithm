#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<long long, int> a, pair<long long, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    int N=0;
    long long n = 0; 
    map<long long, int> m1;
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> n;
        if(m1.find(n) != m1.end()) {
            m1[n]++;
        } else {
            m1[n] = 1;
        }
    }
    
    vector<pair<long long, int>> v1(m1.begin(), m1.end());
    sort(v1.begin(), v1.end(), cmp);
    
    cout << v1[0].first;
    
    return 0;
}