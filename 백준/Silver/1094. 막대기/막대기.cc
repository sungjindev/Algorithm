#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    int x = 0;
    int sum = 64;
    deque<int> dq1(1,64);
    cin >> x;
    
    while(sum > x) {
        int temp = dq1.back()/2;
        dq1.pop_back();
        if(sum-temp >= x) {
            dq1.push_back(temp);
            sum -= temp;
        } else {
            dq1.push_back(temp);
            dq1.push_back(temp);
        }
    }
    
    cout << dq1.size();
    
    return 0;
}