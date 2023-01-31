#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    int N=0;
    string temp, cmd;
    queue<int> q;
    cin >> N;
    cin.ignore();
    cin.clear();
    
    for(int i=0; i<N; i++) {
        getline(cin, cmd);
        stringstream ss(cmd);
        ss >> temp;
        if(temp=="push") {
            ss >> temp;
            q.push(stoi(temp));
        } else if(temp=="pop") {
            if(q.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        } else if(temp=="size") {
            cout << q.size() << "\n";
        } else if(temp=="empty") {
            cout << q.empty() << "\n";
        } else if(temp=="front") {
            if(q.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << q.front() << "\n";
        } else if(temp=="back") {
            if(q.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << q.back() << "\n";
        }
        
    }
    
    return 0;
}