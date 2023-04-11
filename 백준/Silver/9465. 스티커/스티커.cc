//11:50
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,t=0;
    vector<vector<int>> v1;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int arrRow0[100001] = {0,}; //Row 0, Column n에서 스티커를 뗄 때까지의 최댓값
        int arrRow1[100001] = {0,}; //Row 1, Column n에서 스티커를 뗄 때까지의 최댓값
        int num=0;
        cin >> n;
        v1 = vector<vector<int>>(2, vector<int>(n+1,0));
        
        for(int j=0; j<2; j++) {
            for(int z=1; z<=n; z++) {
                cin >> num;
                v1[j][z] = num;
            }
        }
        
        arrRow0[1] = v1[0][1]; //50
        arrRow1[1] = v1[1][1]; //30
        arrRow0[2] = arrRow1[1] + v1[0][2]; //40
        arrRow1[2] = arrRow0[1] + v1[1][2]; //100
        
        for(int z=3; z<=n; z++) {
            arrRow0[z] = max(arrRow1[z-1], arrRow1[z-2]) + v1[0][z]; //200,150   130,60
            arrRow1[z] = max(arrRow0[z-1], arrRow0[z-2]) + v1[1][z]; //110,100
        }
        
        cout << max(arrRow0[n],arrRow1[n]) << "\n";
        
    }

    
    return 0;
}