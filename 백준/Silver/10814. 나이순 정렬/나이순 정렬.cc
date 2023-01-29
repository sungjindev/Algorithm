#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
}

int main(void) {
    int age,n=0;
    string name;
    cin >> n;
    vector<pair<int,string>> users;
    
    for(int i=0; i<n; i++) {
        cin >> age >> name;
        users.push_back({age,name});
    }
    
    stable_sort(users.begin(), users.end(), cmp);
    
    for(auto i: users) {
        cout << i.first <<  " " << i.second << "\n";
    }
    
    return 0;
}