#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cout << fixed;
    cout.precision(3);
    
    int tc;
    cin >> tc;
    int n,temp;
    for(int i=0; i<tc; i++) {
        vector<int> v1;
        double count =0 ;
        double sum=0.0;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> temp;
            sum += temp;
            v1.push_back(temp);
        }
        cin.ignore();
        for(int i: v1) {
            if(i>sum/n)
                count++;
        }
        cout << count/n*100 << "%" << '\n';
    }
    
    return 0;
}