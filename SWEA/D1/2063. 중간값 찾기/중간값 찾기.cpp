#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int temp, n=0;
    cin >> n;
    vector<int> v1;
    
    for(int i=0; i<n; ++i) {
    	cin >> temp;
        v1.push_back(temp);
    }
    
    sort(v1.begin(), v1.end());
    cout << v1[n/2];
    
	return 0;
}


