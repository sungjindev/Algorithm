#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main(void) {
    string n;
    int b,sum=0;
    int count=0;
    cin >> n >> b;
    
    for(int i=n.size()-1; i>=0; i--) {
        if(isalpha(n[i])) {
            sum += (n[i]-55) * pow(b,count);
        } else {
            sum += (n[i]-48) * pow(b,count);
        }
        count++;
    }
    
    cout << sum;
    
    return 0;
}