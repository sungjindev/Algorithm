#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,k;
    int temp = 0;
    vector<int> v1;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    cout << v1[k-1];
    return 0;
}