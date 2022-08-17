#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int num=1;
    int temp;
    string n;
    vector<int> v1(10,0);
    for(int i=0; i<3; i++) {
        cin >> temp;
        num *= temp;
    }
    n = to_string(num);
    for(int i=0; i<n.size(); i++) {
        v1[(int)(n[i]-'0')]++;
    }
    for(int i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    
    return 0;
}