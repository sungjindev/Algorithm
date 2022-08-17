#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    string s1;
    int arr[26] = {};
    getline(cin, s1);
    
    for(int i=0; i<26; i++)
        arr[i] = -1;

    for(char alpha='a'; alpha<='z'; alpha++) {
        int index = s1.find(alpha);
        if(index != string::npos) {
            arr[(int)(alpha-'a')] = index;
        }
    }
    
    for(int i=0; i<26; i++) {
        cout << arr[i] << " ";    
    }
    
    return 0;
}

