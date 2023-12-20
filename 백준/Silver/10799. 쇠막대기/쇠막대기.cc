#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    string str1;
    stack<char> st1;
    cin >> str1;
    
    for(int i=0; i<str1.size(); ++i) {
        if(str1[i] == '(')
            st1.push(str1[i]);
        else {
            if(str1[i-1] == '(') {
                st1.pop();
                answer += st1.size();
            } else {
                st1.pop();
                ++answer;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}