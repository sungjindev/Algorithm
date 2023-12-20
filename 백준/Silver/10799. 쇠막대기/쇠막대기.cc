#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    string str1;
    stack<string> st1;
    cin >> str1;
    
    for(auto ch: str1) {
        if(ch == '(') {
            string temp;
            temp += ch;
            st1.push(temp);
        } else if(ch == ')') {
            if(st1.top() == "(") {
                st1.pop();
                st1.push("1");
            } else {
                int count = 0;
                while(st1.top() != "(") {
                    count += stoi(st1.top());
                    st1.pop();
                }
                st1.pop();
                answer += (count+1);
                
                st1.push(to_string(count));
            }
        }
    }
    
    cout << answer;
    
    return 0;
}