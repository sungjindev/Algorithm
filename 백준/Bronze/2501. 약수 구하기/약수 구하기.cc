#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n,k;
    vector<int> result;
    cin >> n >> k;
    
    for(int i=1; i<=n; i++) {
        if(!(n%i))
            result.push_back(i);
    }   
    
    if(result.size() < k)
        cout << "0";
    else
        cout << result[k-1];
    
    return 0;
}