#include <iostream>
using namespace std;

int main(void) {
    int n,count=0;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int temp=i;
        while(1) {
            if(temp % 5 == 0) {
                count++;
                temp /= 5;
            } else {
                break;
            }
        }
    }
    
    cout << count;
    return 0;
}