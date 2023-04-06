#include <iostream>
using namespace std;

int main(void) {
    pair<int,int> p;
    int num,max=0;
    
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
           cin >> num;
           if(!i && !j) {
               max = num;
               p.first = i+1;
               p.second = j+1;
               continue;
           }
           if(max < num) {
               max = num;
               p.first = i+1;
               p.second = j+1;
           }
        }
    }
    
    cout << max << "\n";
    cout << p.first << " " << p.second;
}