#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int temp;
    
    for(int i=0; i<3; ++i) {
        int bae=0;
        int dueng=0;
        for(int j=0; j<4; ++j) {
            cin >> temp;
            if(temp)
                dueng++;
            else
                bae++;
        }
        
        switch(bae) {
            case 0:
                cout << "E" << "\n";
                break;
            case 1:
                cout << "A" << "\n";
                break;
            case 2:
                cout << "B" << "\n";
                break;
            case 3:
                cout << "C" << "\n";
                break;
            case 4:
                cout << "D" << "\n";
                break;
        }
    }
    
    return 0;
}