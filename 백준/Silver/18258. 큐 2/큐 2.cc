#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0;
    queue<int> q1;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string command;
        cin >> command;
        if(command == "push") {
            int num;
            cin >> num;
            q1.push(num);
        } else if(command == "pop") {
            if(!q1.size()) {
                cout << "-1" << "\n";
                continue;
            } else {
                cout << q1.front() << "\n";
                q1.pop();
            }
        } else if(command == "size") {
            cout << q1.size() << "\n";
        } else if(command == "empty") {
            if(q1.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        } else if(command == "front") {
            if(!q1.size()) {
                cout << "-1" << "\n";
            } else {
                cout << q1.front() << "\n";
            }
        } else if(command == "back") {
            if(!q1.size()) {
                cout << "-1" << "\n";
            } else {
                cout << q1.back() << "\n";
            }
        }
    }
    
    return 0;    
}
