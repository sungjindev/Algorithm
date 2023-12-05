#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ySum=0;
    int mSum=0;
    int temp,n=0;
    
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        cin >> temp;
        ySum += (temp/30+1)*10;
        mSum += (temp/60+1)*15;
    }
    
    if(ySum == mSum) {
        cout << "Y M " << ySum;
    } else if(ySum < mSum) {
        cout << "Y " << ySum;
    } else {
        cout << "M " << mSum;
    }
    
    return 0;
}