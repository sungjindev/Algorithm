#include <iostream>
using namespace std;

int main(void) {
    int arr1[30] = {0,};
    int num = 0;
    
    for(int i=0; i<28; i++) {
        cin >> num;
        arr1[num-1] = 1;
    }
    
    for(int j=0; j<30; j++) {
        if(!arr1[j])
            cout << j+1 << "\n";
    }
    
    return 0;
}