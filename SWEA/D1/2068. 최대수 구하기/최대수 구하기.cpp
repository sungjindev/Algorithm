#include <iostream>
using namespace std;

int main(void) {
    int t=0;
    cin >> t;
    int temp = 0;
    int max = 0;
    
    for(int i=0; i<t; i++) {
    	for(int j=0; j<10; j++) {
        	cin >> temp;
            if(temp>max)
                max = temp;
        }
        cout << "#" << i+1 << " " << max << "\n";
        max=0;
    }
    
    
	return 0;
}