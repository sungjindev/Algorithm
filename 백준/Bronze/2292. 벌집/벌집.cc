#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n==1) {
        cout << "1";
        return 0;
    }
    
    int temp = 1;
    for(int i=1; ; i++) {
        if(n>temp && n<=temp+i*6) {
            cout << i+1;
            break;
        }
        else        
            temp = temp+i*6;
    }
    return 0;
}