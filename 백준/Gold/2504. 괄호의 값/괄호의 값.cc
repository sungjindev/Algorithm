#include <iostream>
#include <stack>
#include <string>
using namespace std;

//내가 생각한 알고리즘
//1. ( 괄호가 열리면 누적곱 변수에 2를 곱하고 [ 괄호가 열리면 누적곱 변수에 3을 곱한다.
//2. [] 던 ()던 괄호가 곧바로 닫히는 경우에는 누적곱 변수를 답안 점수에 합산한 뒤 ]로 닫힌 경우는 누적곱 변수를 3으로 나눠주고
// )로 닫힌 경우에는 누적곱 변수를 2로 나눠준다.
//3. 그 과정에서 올바른 괄호쌍이 아니면 브레이크를 걸어주고 0을 출력한다.

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str1;
    stack<char> st1;
    int sum = 1;    //누적곱 변수
    int answer = 0; //답안 변수
    cin >> str1;
    
    for(int i=0; i<str1.size(); ++i) {
        if(str1[i] == '(') {
            sum *= 2;
            st1.push(str1[i]);
            continue;
        } else if(str1[i] == '[') {
            sum *= 3;
            st1.push(str1[i]);
            continue;
        } else if(str1[i] == ')') {
            if(st1.empty() || st1.top() != '(') {
                answer = 0;
                break;
            }
            
            if(str1[i-1] == '(') {
                answer += sum;
            }
            sum /= 2;
            st1.pop();
        } else if(str1[i] == ']') {
            if(st1.empty() || st1.top() != '[') {
                answer = 0;
                break;
            }
            
            if(str1[i-1] == '[') {
                answer += sum;
            }
            sum /= 3;
            st1.pop();
        } else {
            answer = 0;
            break;
        }
    }
    
    if(!st1.empty())
        answer = 0;
        
    cout << answer;
    return 0;
}