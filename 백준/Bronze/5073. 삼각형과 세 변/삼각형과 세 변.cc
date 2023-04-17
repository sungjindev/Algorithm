#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int a,b,c;
    while(cin >> a && cin >> b && cin >> c && a && b && c) {
        vector<int> v1;
        v1.push_back(a);
        v1.push_back(b);
        v1.push_back(c);
        sort(v1.begin(), v1.end());
        if(v1[0]+v1[1] > v1[2]) {
            if(v1[0] == v1[1] && v1[1] == v1[2]) {
                cout << "Equilateral" << "\n";
            } else if(v1[0] == v1[1] || v1[0] == v1[2] || v1[1] == v1[2]){
                cout << "Isosceles" << "\n";
            } else if(v1[0] != v1[1] && v1[0] != v1[2] && v1[1] != v1[2] ) {
                cout << "Scalene" << "\n";
            }
        } else {
            cout << "Invalid" << '\n';
        }
    }
    
    return 0;
}