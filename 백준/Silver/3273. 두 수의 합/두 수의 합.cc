#include <iostream>
using namespace std;

int main(void) {
    int temp, n=0;
    int count = 0;
    int visited[2000001] = {0,};
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        cin >> temp;
        visited[temp]++;
    }
    
    cin >> temp;
    
    for(int i=1; i<1000001; ++i) {
        if((temp-i) >= 1 && visited[i] && ((temp-i) != i) && visited[temp-i]) {
            count++;
        }
    }
    
    cout << count/2;
    return 0;
}