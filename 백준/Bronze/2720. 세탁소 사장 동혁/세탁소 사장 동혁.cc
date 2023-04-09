#include <iostream>
using namespace std;

int main(void) {
    int money,t=0;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> money;
        cout << money / 25 << " ";
        money %= 25;
        
        cout << money / 10 << " ";
        money %= 10;
        
        cout << money / 5 << " ";
        money %= 5;
        
        cout << money << "\n"; 
    }
    return 0;
}