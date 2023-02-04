#include <iostream>
using namespace std;

int main(void) {
    int e,s,m,num;
    cin >> e >> s >> m;
    
    for(int i=0; ; i++) {
        bool scheck,mcheck;
        num = (15*i)+e;
        
        if(num%28==0) {
            s==28? scheck=true: scheck=false;
        } else {
            num%28==s? scheck=true: scheck=false;
        }
        
        if(num%19==0) {
            m==19? mcheck=true: mcheck=false;
        } else {
            num%19==m? mcheck=true: mcheck=false;
        }
        
        if(mcheck&&scheck) {
            cout << num;
            break;
        }
        
    }
    
    return 0;
}