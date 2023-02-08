#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main(void) {
    int a,b,m,temp,sum=0;
    stack<int> s1;
    cin >> a >> b >> m;
    int mul = pow(a,m-1);
    
    for(int i=0; i<m; i++) {
        cin >> temp;
        sum += temp*mul;
        mul /= a;
    }
    
    while(sum != 0) {
        s1.push(sum%b);
        sum /= b;
    }
    
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    
    return 0;
}