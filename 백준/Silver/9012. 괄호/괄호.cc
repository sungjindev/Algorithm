#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    int T=0;
    string temp;
    cin >> T;
    cin.ignore();
    cin.clear();
    
    for(int i=0; i<T; i++) {
        bool flag = true;
        stack<int> st;
        getline(cin,temp);

        for(auto it = temp.begin(); it != temp.end(); it++) {
           if(*it == '(') {
               st.push(1);
           } else if(*it == ')') {
               if(st.empty()) {
                   cout << "NO" << "\n";
                   flag = false;
                   break;
               }
               st.pop();
           }
        }
        
        if(!flag)
            continue;

        if(st.empty()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}