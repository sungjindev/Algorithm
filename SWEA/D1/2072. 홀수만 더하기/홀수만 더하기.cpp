#include <iostream>
using namespace std;

int main(void) {
    int t = 0;
    int num = 0;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int sum=0;
    	for(int j=0; j<10; j++) {
        	cin >> num;
            if(num % 2 != 0) {
            	sum += num;
            }
        }
        cout << "#" << i+1 << " " << sum << "\n";
    }
    
	return 0;
}