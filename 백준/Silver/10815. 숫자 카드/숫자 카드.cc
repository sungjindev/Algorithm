#include <iostream>
using namespace std;

bool arr1[20000001] = {0,};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,temp;
    cin >> n;

    for(int i=0; i<n; ++i) {
        cin >> temp;
        arr1[temp+10000000] = true;
    }
    
    cin >> m;
    
    for(int i=0; i<m; ++i) {
        cin >> temp;
        if(arr1[temp+10000000])
            cout << "1 ";
        else
            cout << "0 ";
    }
    
    return 0;
}