#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cout << fixed;
    cout.precision(6);
    int num,m;
    double sum=0.0;
    double temp;
    vector<double> v1;
    cin >> num;
    for(int i=0; i<num; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    
    m = *max_element(v1.begin(),v1.end());
    
    for(int i=0; i<num; i++) {
        v1[i] = v1[i]/m*100.0;
        sum += v1[i];
    }
    
    cout << sum/num;
    
    return 0;
}