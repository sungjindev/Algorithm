#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
    string n = "";
    cin >> n;
    vector<int> v1;

    for(int i=0; i<n.size(); i++) {
        v1.push_back(n[i]-'0');
    }
    sort(v1.begin(),v1.end(),greater<int>());
    
    for(int j=0; j<v1.size(); j++) {
        cout << v1[j];
    }
    
    return 0;
}