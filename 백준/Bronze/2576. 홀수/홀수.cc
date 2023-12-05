#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int temp;
    int min=101;
    int count=0;
    int sum=0;
    
    for(int i=0; i<7; ++i) {
        cin >> temp;
        
        if(temp%2==1) {
            count++;
            if(temp < min)
                min = temp;
            sum += temp;
        }
    }
    
    if(!count)
        cout << "-1";
    else {
        cout << sum << "\n" << min;
    }
    
    return 0;
}