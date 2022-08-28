#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n = 0;
    vector<int> v1;
    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(),v1.end());
    
    for(int j=0; j<n; j++) {
        cout << v1[j] << '\n';
    }
    return 0;
}