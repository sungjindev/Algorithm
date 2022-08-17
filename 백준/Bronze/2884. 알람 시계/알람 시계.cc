#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(void) {
    string hm;
    int h,m;
    int min;
    getline(cin, hm);
    stringstream ss(hm);
    ss >> h;
    ss >> m;
    min = h * 60 + m - 45;
    if(min < 0) {
        cout << "23 " << 60+min;
    } else {
        cout << min/60 << " " <<min%60;
    }
    
    return 0;
}