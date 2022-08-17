#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t,h,w,n;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> h >> w >> n;
        string x,y;
        int temp;
        if(n % h == 0)
            x = to_string(h); 
        else
            x = to_string(n % h);
            
        if(n%h == 0) {
            temp = (n/h);
        } else {
            temp = (n/h+1);
        }
        
        if(temp < 10)
            y = "0" + to_string(temp); 
        else
            y = to_string(temp);
        
        cout << x+y << '\n';
    }
    
    return 0;
}