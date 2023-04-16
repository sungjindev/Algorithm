#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v1;
    int num=0;
    int sum=0;
    int med=0;
    for(int i=0; i<5; i++) {
        cin >> num;
        sum += num;
        v1.push_back(num);
    }
    
    sort(v1.begin(), v1.end());
    
    cout << sum/5 << "\n" << v1[2];

    
    
    
    return 0;
}