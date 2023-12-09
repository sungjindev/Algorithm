#include <iostream>
#include <list>
#include <string>
using namespace std;

void operation(char ch1, list<char>& li1, list<char>::iterator& it) {
    if(ch1 == '<') {
        if(it != li1.begin()) {
            it--;
        }
    } else if(ch1 == '>') {
        if(++it == li1.end()) {
            --it;
        }
    } else if(ch1 == '-') {
        if(it != li1.begin()) {
            li1.erase(it--);
        }
    } else {
        it = li1.insert(++it, ch1);
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t=0;
    cin >> t;

    for(int i=0; i<t; ++i) {
        list<char> li1(1,'*');
        string str1;
        cin >> str1;
        list<char>::iterator it = li1.begin();
        for(int j=0; j<str1.size(); ++j) {
            operation(str1[j], li1, it);
        }
        
        for(auto k=++li1.begin(); k != li1.end(); ++k) {
            cout << *k;
        }
        cout << "\n";
    }
    
    return 0;
}