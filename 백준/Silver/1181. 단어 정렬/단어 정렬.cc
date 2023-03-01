#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main(void) {
    string str1;
    set<string> s1;
    int n=0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> str1;
        s1.insert(str1);
    }
    vector<string> v1(s1.begin(), s1.end());
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(auto v: v1) {
        cout << v << "\n";
    }
    
    return 0;
}