#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    string s1,num1,num2;
    getline(cin, s1);
    stringstream ss(s1);
    
    ss >> num1;
    ss >> num2;
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    if(stoi(num1) > stoi(num2))
        cout << num1;
    else
        cout << num2;

    return 0;
}