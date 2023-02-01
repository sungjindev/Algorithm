#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string word;
    int count[26] = {0,};
    
    cin >> word;
    
    for(int i=0; i<word.size(); i++) {
        count[word[i]-'a']++;
    }
    
    for(int j=0; j<26; j++) {
        cout << count[j] << " ";
    }
    
    return 0;
}