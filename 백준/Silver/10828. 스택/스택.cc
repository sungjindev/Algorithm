#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    int n=0;
    string cmd;
    stack<int> st;
    cin >> n;
    cin.ignore();
    cin.clear();
    for(int i=0; i<n; i++) {
        getline(cin,cmd);
        string temp;
        stringstream ss(cmd);
        while(ss >> temp) {
            if(temp == "push") {
                ss >> temp;
                st.push(stoi(temp));
            } else if(temp == "pop") {
                if(st.empty())
                    cout << "-1" << "\n";
                else {
                    cout << st.top() << "\n";
                    st.pop();
                }
            } else if(temp == "size") {
                cout << st.size() << "\n";
            } else if(temp == "empty") {
                if(st.empty())
                    cout << "1" << "\n";
                else
                    cout << "0" << "\n";
            } else if(temp == "top") {
                if(st.empty())
                    cout << "-1" << "\n";
                else
                    cout << st.top() << "\n";
            }
        }
    }
    
    return 0;
}