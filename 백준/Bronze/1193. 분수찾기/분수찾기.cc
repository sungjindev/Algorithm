#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int sum=0;
    cin >> n;
    string s1;
    
    for(int i=1; ; i++) {
        if(sum+i < n) {
            sum += i;
            continue;
        } else {
            if(i%2==1) {
                for(int j=i; j>0; j--) {
                    sum++;
                    if(sum == n) {
                        s1 += to_string(j);
                        s1 += "/";
                        s1 += to_string(i+1-j);
                        cout << s1;
                        return 0;
                    }
                }
            } else {
                for(int z=1; z<=i; z++) {
                    sum++;
                    if(sum == n) {
                        s1 += to_string(z);
                        s1 += "/";
                        s1 += to_string(i+1-z);
                        cout << s1;
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}