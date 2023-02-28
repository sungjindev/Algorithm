#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x1,y1,x2,y2,r1,r2,n;
    int d,d1,d2;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        d1 = (r1-r2)*(r1-r2);
        d2 = (r1+r2)*(r1+r2);
        
        if(d==0) {
            if(d1==0)
                cout << "-1" << "\n";
            else
                cout << "0" << "\n";
        } else if(d == d1 || d == d2)
            cout << "1" << "\n";
        else if(d1  < d && d < d2)
            cout << "2" << "\n";
        else
            cout << "0" << "\n";
    }
    
    return 0;
}