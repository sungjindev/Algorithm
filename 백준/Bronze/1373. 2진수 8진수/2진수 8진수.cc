#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
    string str1,temp;
    stack<int> s1;
    int i=0;
    int sum=0;
    int mul = 1;
    cin >> str1;
    
    reverse(str1.begin(), str1.end());
    
    if(str1.size()<=3) {
        for(int j=i; j<str1.size(); j++) {
            sum += (str1[j]-'0')*mul;
            mul *= 2;
        }
        cout << sum;
        return 0;
    }
    
    for(; i<str1.size()-2; i+=3) {
        temp = str1.substr(i,3);
        s1.push(((temp[0]-'0') * 1 + (temp[1]-'0') * 2 + (temp[2]-'0') * 4));
    }
    
    sum = 0;
    for(int j=i; j<str1.size(); j++) {
        sum += (str1[j]-'0')*mul;
        mul *= 2;
    }
    if(sum!=0)
        s1.push(sum);
    
    while(!s1.empty()) {
        cout << s1.top();
        s1.pop();
    }
    
    return 0;
}