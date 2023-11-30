#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1;
    cin >> str1;
    
    for(int i=0; i<str1.size(); ++i) {
    	cout << str1[i]-'A'+1 << " ";
    }
    
	return 0;
}