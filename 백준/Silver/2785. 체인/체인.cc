#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,temp,count=0;
    vector<int> v1;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    sort(v1.begin(), v1.end(), greater<int>());
    int j = n-1;
    for(int i=0; i<n; ) {
        if(i+v1[j] < j-1) {
            count += v1[j];
            i += v1[j];
            j--;
        } else if(i+v1[j] == j-1) {
            count += v1[j];
            cout << count;
            break;
        } else if(i+v1[j] > j-1) {
            count += j-i;
            cout << count;
            break;
        }
    }
    
    return 0;
}