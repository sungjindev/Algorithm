#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n=0;

    while(cin >> n && (n != -1)) {
        int sum=0;
        vector<int> v1;
        for(int i=1; i<n; i++) {
            if(n%i==0) {
                sum+=i;
                v1.push_back(i);
            }
        }
        if(sum == n) {
            cout << n << " = " << v1[0];
            for(int i=1; i<v1.size(); i++) {
                cout << " + " << v1[i];
            }
            cout << "\n";
        } else {
            cout << n << " is NOT perfect." << "\n";
        }
    }
    
    return 0;
}