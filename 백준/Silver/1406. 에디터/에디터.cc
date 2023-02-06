#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str1,cmd;
    char data;
    int num = 0;
    cin >> str1 >> num;
    
    list<char> list1(str1.begin(), str1.end());
    list<char>::iterator it = list1.end();
    
    for(int i=0; i<num; i++) {
        cin >> cmd;
        if(cmd == "L") {
            if(it != list1.begin())
                --it;
        } else if(cmd == "D") {
            if(it != list1.end())
                ++it;
        } else if(cmd == "B") {
            if(it != list1.begin())
                it = list1.erase(--it);
        } else if(cmd == "P") {
            cin >> data;
            list1.insert(it, data);
        }
    }
    
    for(it = list1.begin(); it != list1.end(); ++it) {
        cout << *it;
    }
    
    
    
    return 0;
}