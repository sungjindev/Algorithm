#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void) {
    int n,m,count=0;
    string temp;
    unordered_map<string,int> um;
    
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) {
        cin >> temp;
        um[temp] = 1;
    }
    
    for(int j=0; j<m; ++j) {
        cin >> temp;
        if(um[temp] == 1)
            count++;
    }
    
    cout << count;
    
    return 0;
}