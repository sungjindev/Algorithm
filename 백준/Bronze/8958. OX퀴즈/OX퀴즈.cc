#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    char arr[80];
    string str;
    int score[80] = {};
    
    for(int i=1; i<80; i++) {
        for(int j=1; j<=i; j++) {
            score[i] += j;
        }
    }
    
    for(int i=0; i<n; i++) {
        int result = 0;
        getline(cin, str);
        strcpy(arr, str.c_str());
        
        char* temp = strtok(arr, "X");
        while(temp != NULL) {
            result += score[strlen(temp)];
            temp = strtok(NULL, "X");
        }
        
        cout << result << '\n';
    }
    
    return 0;
}