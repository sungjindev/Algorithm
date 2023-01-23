#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v1;
    int n,v,temp;
    int count = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    cin >> v;
    
    for(int j: v1) {
        if(j == v)
            count++;
    }
    
    cout << count;
    return 0;
}