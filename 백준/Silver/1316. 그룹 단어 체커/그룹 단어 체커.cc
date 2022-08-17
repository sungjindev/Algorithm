#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    string s1;
    cin >> num;
    int count = num;
    cin.ignore();
    for(int i=0; i<num; i++) {
        vector<int> v1(26,0);
        getline(cin,s1);
        char before = s1[0];
        v1[s1[0]-'a']++;
        for(int j=1; j<s1.size(); j++) {
            if(v1[s1[j]-'a'] == 0) {
                v1[s1[j]-'a']++;
                before = s1[j];
                continue;
            }
            else {
                if(before != s1[j]) {
                    count--;
                    break;
                }
            }
        }
    }

    cout << count;

    return 0;
}