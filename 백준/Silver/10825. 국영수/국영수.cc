#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct person {
    string name;
    int k,e,m;
    person(string name1, int k1, int e1, int m1) :name(name1), k(k1), e(e1), m(m1) {}; 
};

bool cmp(person a, person b) {
    if(a.k == b.k && a.e == b.e && a.m == b.m)
        return a.name < b.name;
    if(a.k == b.k && a.e == b.e)
        return a.m > b.m;
    if(a.k == b.k)
        return a.e < b.e;
    return a.k > b.k;
}

int main(void) {
    int n=0;
    vector<person> lists;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string tname;
        int tk,te,tm;
        cin >> tname >> tk >> te >> tm;
        lists.push_back(person(tname,tk,te,tm));    
    }
    
    sort(lists.begin(), lists.end(), cmp);
    
    for(auto i: lists) {
        cout << i.name << "\n";
    }
    
    
    return 0;
}