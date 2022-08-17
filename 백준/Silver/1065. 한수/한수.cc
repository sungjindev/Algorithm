#include <iostream>
#include <vector>
using namespace std;

int d(int n) {
    int count = 0;
    for(int i=1; i<=n; i++) {
        int gap;
        int temp = i;
        vector<int> v1;
        while(temp != 0) {
            v1.push_back(temp%10);
            temp = temp/10;
        }
        
        if(v1.size() <= 2)
            count++;
        else {
            int j;
            gap = v1[1] - v1[0];
            for(j=1; j<v1.size()-1; j++) {
                if(gap != v1[j+1] - v1[j]) {
                    break;
                }
            }
            if(j == v1.size()-1)
                count++;
        }
        
    }
    return count;
}


int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << d(n);
    
    return 0;
}