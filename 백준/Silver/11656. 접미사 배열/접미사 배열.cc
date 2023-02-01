#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void) {
    string str;
    set<string> s;
    cin >> str;
    
    for(int i=0; i<str.size(); i++) {
        s.insert(str.substr(i));
    }
    
    for(auto e: s) {
        cout << e << "\n";
    }
    
    return 0;
}