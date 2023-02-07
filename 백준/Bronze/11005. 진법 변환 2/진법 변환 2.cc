#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int n,b;
    stack<int> s1;
    cin >> n >> b;
    
    while((n/b) >= 1) {
        s1.push(n%b);
        n/=b;
    }
    s1.push(n%b);
    
    while(!s1.empty()) {
        if(s1.top()>=10)
            printf("%c", s1.top()+55);
        else
            cout << s1.top();
        s1.pop();
    }
    
    return 0;
}