#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int rule[] = {1,1,2,2,2,8};
    int temp;
    for(int i=0; i<6; i++) {
        cin >> temp;
        cout << rule[i] - temp << " ";
    }
    
    return 0;
}