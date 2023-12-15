#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int temp,n=0;
    int current = 1;
    cin >> n;
    string str1="";
    vector<int> v1;
    stack<int> st1;

    for(int i=0; i<n; ++i) {
        cin >> temp;
        v1.push_back(temp);
    }

    for(int i=0; i<n; ++i) {
        while(current <= v1[i]) {
            st1.push(current++);
            str1 += "+";
        }
        
        if(st1.top() == v1[i]) {
            st1.pop();
            str1 += "-";
        } else {
            str1 = "NO";
            break;
        }
    }
    
    if(str1 == "NO") {
        cout << str1;
    } else {
        for(auto v: str1)
            cout << v << "\n";
    }
    
    return 0;
}