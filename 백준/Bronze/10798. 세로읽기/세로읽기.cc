#include <iostream>
#include <string>
using namespace std;

int main(void) {
    char arr[5][15] = {0,};
    string str1;
    string word="";
    
    for(int i=0; i<5; i++) {
        cin >> str1;
        for(int j=0; j<str1.size(); j++) {
            arr[i][j] = str1[j];
        }
    }
    
    for(int i=0; i<15; i++) {
        for(int j=0; j<5; j++) {
            if(!arr[j][i])
                continue;
            else
                word.push_back(arr[j][i]);
        }
    }
    
    cout << word;
    
    return 0;
}