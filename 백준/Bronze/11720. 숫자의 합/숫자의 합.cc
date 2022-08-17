#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int n;
    int sum = 0;
    string s1;
    cin >> n;
    cin.ignore();
    getline(cin, s1);
    
    for(int i=0; i<s1.size(); i++) {
        sum += (int)(s1[i]-'0');
    }
    
    cout << sum;

    return 0;
}

