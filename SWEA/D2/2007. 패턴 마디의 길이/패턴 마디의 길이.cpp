#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int t=0;
    string str1="";
    cin >> t;
    
    for(int i=0; i<t; i++) {
    	cin >> str1;
        string tempStr = str1.substr(0,1);
        for(int j=1; j<str1.size(); j++) {
            int index = str1.find(tempStr, tempStr.size());
        	if(index == tempStr.size()) {
                cout << "#" << i+1 << " " << tempStr.size() << "\n";
                break;
            } else {
            	tempStr += str1[j];
            }
        }
    }
    
	return 0;
}