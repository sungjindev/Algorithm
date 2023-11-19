#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int t=0;
    int a,b;
    string result = "";
    cin >> t;
    
    for(int i=0; i<t; i++) {
    	cin >> a >> b;
        if(a>b) {
        	result = ">";
        } else if(a==b) {
        	result = "=";
        } else {
        	result = "<";
        }
        cout << "#" << i+1 << " " << result << "\n";
    }
    
	return 0;
}