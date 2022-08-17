#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int tc;
    int num;
    string s1;
    cin >> tc;
    for(int i=0; i<tc; i++) {
        cin.ignore();
        cin >> num;
        cin >> s1;
        for(int j=0; j<s1.size(); j=j+num) {
            string temp;
            for(int z=0; z<num; z++) {
                temp += s1[j];
            }
            s1.replace(j,1,temp);
        }
        cout << s1 << '\n';
    }
    
    return 0;
}

