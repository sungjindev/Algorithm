#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <queue>
using namespace std;

int main(void) {
    string str1 = "";
    cin >> str1;
    str1 = "+" + str1;
    vector<int> indexMinus;
    queue<char> q1;
    int num, sum=0;
    stringstream ss;
    
    for(int i=0; i<str1.size(); i++) {
        if(str1[i] == '-')
            indexMinus.push_back(i);
    }
    
    if(indexMinus.size()) {
        for(int j=0; j<indexMinus.size(); j++) {
            if(indexMinus.size()-1 != j) {
                for(int z=indexMinus[j]+1; z<indexMinus[j+1]; z++) {
                    if(str1[z] == '+')
                        str1[z] = '-';
                }
            } else {
                for(int z=indexMinus[j]+1; z<str1.size(); z++) {
                    if(str1[z] == '+')
                        str1[z] = '-';
                }
            }
        }
    }
    
    for(int i=0; i<str1.size(); i++) {
        if(!isdigit(str1[i])) {
            q1.push(str1[i]);
            str1[i] = ' ';
        }
    }
    
    ss.str(str1);
    
    while(ss >> num) {
        if(q1.front() == '+') {
            sum += num;
        } else {
            sum -= num;
        }
        q1.pop();
    }
    
    cout << sum;
    
    return 0;
}