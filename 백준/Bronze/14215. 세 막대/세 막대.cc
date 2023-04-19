#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int a,b,c;
    vector<int> v1;
    cin >> a >> b >> c;
    
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    
    sort(v1.begin(), v1.end());
    
    if(v1[2] >= v1[0]+v1[1]) {
        cout << (v1[0]+v1[1])*2-1;
    } else {
        cout << v1[0]+v1[1]+v1[2];
    }
    
    return 0;
}