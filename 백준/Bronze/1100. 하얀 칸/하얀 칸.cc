#include <iostream>
using namespace std;

int main(void) {
    int count = 0;
    char c;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> c;
            if(i%2==0 && j%2==0 && c == 'F')
                count++;
            else if(i%2==1 && j%2==1 && c == 'F')
                count++;
        }
    }
    
    cout << count;
    
    return 0;
}