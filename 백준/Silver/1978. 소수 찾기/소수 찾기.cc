#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int primeNumber(multiset<int>& ms1) {
    int count = 0;
    int j = 0;
    for(auto it=ms1.begin(); it!=ms1.end(); ++it) {
        for(j=2; j<=(int)sqrt(*it); ++j) {
            if((*it) % j == 0)
                break;
        }
        if(*it == 1)
            continue;
            
        if(*it == 2 || *it == 3) {
            count++;
            continue;
        }
        
        if(j > (int)sqrt(*it))
            count++;
    }

    return count;
}

int main(void) {
    int n = 0;
    int temp = 0;
    multiset<int> ms1;
    
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> temp;
        ms1.insert(temp);
    }
    
    cout << primeNumber(ms1);
    
    return 0;
}