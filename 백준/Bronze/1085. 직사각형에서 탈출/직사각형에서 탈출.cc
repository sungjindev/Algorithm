#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int x,y,w,h;
    int min=0;    
    cin >> x >> y >> w >> h;
    
    min = x;
    
    if(min > y)
        min = y;
    
    if(min > w-x)
        min = w-x;
    
    if(min > h-y)
        min = h-y;
        
    cout << min;

    return 0;
}