#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int k=0;
    int num = 0;
    stack<int> st1;
    int sum=0;
    cin >> k;
    
    for(int i=0; i<k; i++) {
        cin >> num;
        if(!num) {
            st1.pop();
        } else {
            st1.push(num);
        }
    }
    
    while(st1.size()) {
        sum += st1.top();
        st1.pop();
    }
    cout << sum;
    
    return 0;
}