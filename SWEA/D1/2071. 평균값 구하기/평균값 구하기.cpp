#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int t = 0;
    int num = 0;
    cin >> t;
    
    for(int i=0; i<t; i++){
        double sum = 0.0;
    	for(int j=0; j<10; j++){
        	cin >> num;
            sum += num;
        }
 		cout << "#" << i+1 << " " << floor(sum/10+0.5) << "\n";
    }
    
	return 0;
}