#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s1,temp;
    int count = 0;
    getline(cin, s1);
    stringstream ss(s1);

    while(ss >> temp) {
        count++;
    }

    cout << count;

    return 0;
}