#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1;
    int time = 0;
    vector<int> v1 = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    getline(cin, s1);
    
    for(int i=0; i<s1.size(); i++) {
        time += v1[s1[i]-'A'];
    }
    
    cout << time;

    return 0;
}