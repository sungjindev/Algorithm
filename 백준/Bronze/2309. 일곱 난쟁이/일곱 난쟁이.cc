#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v1;
    int temp=0;
    int sum=0;  //9 난쟁이 총 키의 합
    
    for(int i=0; i<9; ++i) {
        cin >> temp;
        sum += temp;
        v1.push_back(temp);
    }
    
    sort(v1.begin(), v1.end());
    
    for(int i=0; i<8; ++i) {
        for(int j=i+1; j<9; ++j) {
            if(sum-v1[i]-v1[j] == 100) {
                for(auto k: v1) {
                    if(k != v1[i] && k != v1[j])
                        cout << k  << "\n";
                }
                return 0;
            }
        }
    }
    
    return 0;
}