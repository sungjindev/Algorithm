#include <iostream>
#include <string>
using namespace std;

int d(int* arr) {
    for(int i=1; i<=10000; i++) {
        string s = to_string(i);
        int self=0;
        for(int j=0; j<s.length(); j++) {
            self += (int)(s[j]-'0');
        }
        self += i;
        arr[self]++;
    }
    return 0;
}


int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int arr[10040] = {};    //0이면 셀프 넘버
    d(arr);
    
    for(int i=1; i<=10000; i++) {
        if(arr[i] == 0)
            cout << i << '\n';
    }
        
    return 0;
}

