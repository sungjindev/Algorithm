#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1;
    
    while(getline(cin,str1)) {
        int count[4] = {0,};
        for(int i=0; i<str1.size(); i++) {
            if(islower(str1[i])) {
                count[0]++;
            } else if(isupper(str1[i])) {
                count[1]++;
            } else if(isdigit(str1[i])) {
                count[2]++;
            } else if(isspace(str1[i])) {
                count[3]++;
            }
        }
        
        for(int j=0; j<4; j++) {
            cout << count[j] << " ";
        }
    }
    
    return 0;
}