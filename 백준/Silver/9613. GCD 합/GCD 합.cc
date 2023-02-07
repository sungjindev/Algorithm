#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    int r=0;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    int t,n,temp;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        unsigned long long sum=0;
        cin >> n;
        
        vector<int> v1;
        vector<int> v2(n-2,0);
        
        v2.push_back(1);
        v2.push_back(1);
        
        for(int j=0; j<n; j++) {
            cin >> temp;
            v1.push_back(temp);
        }

        do {
            int a,b,count=0;
    
            for(int z=0; z<v2.size(); z++) {
                if(v2[z]==1) {
                    if(!count) {
                        a = v1[z];
                        count++;
                    } else {
                        b = v1[z];
                        sum += (a>b ? GCD(a,b) : GCD(b,a));
                        break;
                    }
                }
            }
        } while(next_permutation(v2.begin(), v2.end()));
        cout << sum << "\n";
    }
}