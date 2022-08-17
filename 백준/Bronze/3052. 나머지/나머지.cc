#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num;
    set<int> s1;
    for(int i=0; i<10; i++) {
        cin >> num;
        s1.insert(num%42);
    }
    cout << s1.size();
    
    return 0;
}