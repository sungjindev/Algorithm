#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for(int i=1;i<=1000000; i++) {
        int sum = i;
        int temp = i;
        while(temp) {
            sum += temp%10;
            temp = temp/10;
        }
        if(sum == n) {
            cout << i;
            return 0;
        }
    }
    cout <<  0;
    
    return 0;
}