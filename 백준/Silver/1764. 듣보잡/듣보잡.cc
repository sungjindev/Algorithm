#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str1 = "";
    unordered_set<string> us1;
    set<string> s1;
    int n,m=0;
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        cin >> str1;
        us1.insert(str1);
    }
    
    for(int i=0; i<m; i++) {
        cin >> str1;
        if(us1.find(str1) != us1.end()) {
            s1.insert(str1);
        }
    }
    
    cout << s1.size() << "\n";
    
    for(auto v: s1) {
        cout << v << "\n";
    }
    
    return 0;
}