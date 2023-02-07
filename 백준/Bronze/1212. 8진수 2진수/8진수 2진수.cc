#include <iostream>
#include <stack>
#include <string>
using namespace std;

string cal(int n) {
    stack<int> s1;
    string result = "";
    
    if(n==0)
        return "000";
    
    while(n != 0) {
        s1.push(n%2);
        n /= 2;
    }
    
    while(!s1.empty()) {
        result += to_string(s1.top());
        s1.pop();
    }
    
    return result;
}

int main(void) {
    string n;
    cin >> n;
    
    if(n=="0") {
        cout << "0";
        return 0;
    }
    
    for(int i=0; i<n.size(); i++) {
        if(i==0) {
            cout << cal(n[i]-'0');
        } else {
            string temp = cal(n[i]-'0');
            if(temp.size()==1)
                temp = "00" + temp;
            else if(temp.size()==2)
                temp = "0" + temp;
            cout << temp;
        }
    }
    
    return 0;
}