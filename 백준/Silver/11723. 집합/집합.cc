#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    string str1;
    set<int> s1;    //이게 시뮬레이션을 돌릴 set이다.
    set<int> allSet;
    cin >> m;

    for(int i=1; i<=20; ++i) {
        allSet.insert(i);   //all 명령어용 set이다.
    }

    while(m--) {
        cin >> str1;
        int num;

        if(str1=="all") {
            s1 = allSet;
            continue;
        } else if(str1=="empty") {
            s1.clear();
            continue;
        }
        
        cin >> num;
        
        if(str1=="add") {
            s1.insert(num);
        } else if(str1=="remove") {
            s1.erase(num);
        } else if(str1=="check") {
            set<int>::iterator tmp = s1.find(num);
            if(tmp != s1.end()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(str1=="toggle") {
            set<int>::iterator tmp = s1.find(num);
            if(tmp != s1.end()) {
                s1.erase(num);
            } else {
                s1.insert(num);
            }
        }
    }
    
    return 0;
}