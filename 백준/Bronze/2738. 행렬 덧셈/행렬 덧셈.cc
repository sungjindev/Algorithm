#include <iostream>
using namespace std;

int main(void) {
    int n,m,temp;
    cin >> n >> m;
    int arr1[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            arr1[i][j] = temp;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            arr1[i][j] += temp;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    
    return 0;
}