#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=0;
    int count=0;
    cin >> n;
    string str1;
    for(int i=0; i<n; ++i) {
        stack<char> st1;
        cin >> str1;
        if(str1.size()%2 == 1)
            continue;
        
        for(auto v: str1) {
            if(st1.empty()) {
                st1.push(v);
                continue;
            }
            
            if(st1.top() == v) {
                st1.pop();
            } else {
                st1.push(v);
            }
        }
        
        if(st1.empty())
            count++;
    }
    
    cout << count;
    
    return 0;
}