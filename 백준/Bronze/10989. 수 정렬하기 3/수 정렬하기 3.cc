#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[10001] = {0};
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    
    for(int j=1; j<=10000; j++) {
        for(int z=1; z<=arr[j]; z++) {
            cout << j << '\n';
        }
    }
    
}