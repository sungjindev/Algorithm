#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<int> v1;
    int a,b;
    
    for(int i=1; i<=20; ++i) {
        v1.push_back(i);
    }
    
    for(int i=0; i<10; ++i) {
        cin >> a >> b;
        reverse(v1.begin()+a-1, v1.begin()+b);
    }
    
    for(auto v: v1)
        cout << v << " ";
    
    return 0;
}