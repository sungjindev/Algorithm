#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int m, d;
    
    cin >> m >> d;
    
    if(m>=2) {
        for(int i=0; i<=m-2; i++) {
            d += month[i];
        }
    }
    cout << day[d%7];
    
    return 0;
}