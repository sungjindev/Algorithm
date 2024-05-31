#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st1;
    
    for(auto v: s) {
        if(v == '(')
            st1.push(v);
        else {
            if(st1.empty()) {
                return false;
            }
            st1.pop();    
        }
    }
    
    if(st1.size())
        return false;
    
    return answer;
}