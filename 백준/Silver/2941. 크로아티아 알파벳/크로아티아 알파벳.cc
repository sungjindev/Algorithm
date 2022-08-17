#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> v1 = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s1;
    int count = 0;
    getline(cin, s1);
    
    while(s1.size() != 0) {
        int j;
        for(j=0; j<v1.size(); j++) {
            if(s1.find(v1[j]) == 0) {
                count++;
                s1.replace(0,v1[j].size(), "");
                break;
            }
        }
        if(j==v1.size()) {
            count++;
            s1.replace(0,1,"");
        }
    }
    
    cout << count;
    return 0;
}