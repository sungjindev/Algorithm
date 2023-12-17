#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=0;
    queue<int> q1;
    cin >> n;
    
    for(int i=1; i<=n; ++i) {
        q1.push(i);
    }
    
    while(q1.size() > 1) {
        q1.pop();
        q1.push(q1.front());
        q1.pop();
    }
    
    cout << q1.front();
    
    return 0;
}