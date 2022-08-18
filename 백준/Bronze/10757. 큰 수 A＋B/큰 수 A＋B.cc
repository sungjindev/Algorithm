#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
    string a = "";
    string b = "";
    string result = "";
    int minSize,i;
    int sum = 0;
    int up = 0;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    if(a.size() < b.size()) {
        minSize = a.size();
        for(i=0; i<minSize; i++) {
            result += to_string(((a[i]-'0')+(b[i]-'0')+up)%10);
                
            up = ((a[i]-'0')+(b[i]-'0')+up)/10;
        }
        
        for(int j=i; j<b.size(); j++) {
            result += to_string((b[j]-'0'+up)%10);
            
            up = ((b[j]-'0')+up)/10;
        }
        
        if(up)
            result += "1";
 
    } else if(a.size() > b.size()) {
        minSize = b.size();
        
        for(i=0; i<minSize; i++) {
            result += to_string(((a[i]-'0')+(b[i]-'0')+up)%10);
                
            up = ((a[i]-'0')+(b[i]-'0')+up)/10;
        }
        
        for(int j=i; j<a.size(); j++) {
            result += to_string((a[j]-'0'+up)%10);
            
            up = ((a[j]-'0')+up)/10;
        }
        
        if(up)
            result += "1";
            
    } else {
        minSize = b.size();
        
        for(i=0; i<minSize; i++) {
            result += to_string(((a[i]-'0')+(b[i]-'0')+up)%10);
                
            up = ((a[i]-'0')+(b[i]-'0')+up)/10;
        }     
        
        if(up)
            result += "1";
    }

    reverse(result.begin(), result.end());
    cout << result;
    
    return 0;
}