#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
    int a,n=0;
    deque<int> dq;
    string temp;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(temp == "push_front") {
            cin >> a;
            dq.push_front(a);
        } else if(temp == "push_back") {
            cin >> a;
            dq.push_back(a);
        } else if(temp == "pop_front") {
            if(dq.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        } else if(temp == "pop_back") {
            if(dq.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        } else if(temp == "size") {
            cout << dq.size() << "\n";
        } else if(temp == "empty") {
            cout << dq.empty() << "\n";
        } else if(temp == "front") {
            if(dq.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << dq.front() << "\n";
        } else if(temp == "back") {
            if(dq.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << dq.back() << "\n";
        }
    }
    
    return 0;
}