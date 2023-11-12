#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
    	string num = to_string(i);
        int count = 0;
        for(int j=0; j<num.size(); j++) {
        	if(num[j]=='3' || num[j]=='6' || num[j]=='9') {
            	count++;
            }
        }
        
        if(count==1)
            cout << "- ";
        else if(count==2)
            cout << "-- ";
        else
            cout << num << " ";
    }
   
	return 0;
}