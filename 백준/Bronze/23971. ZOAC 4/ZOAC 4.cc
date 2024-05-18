#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h,w,n,m,answer=0;
    cin >> h >> w >> n >> m;
    
    for(int i=0; i<h; i+=(n+1)) {   //h가 행의 최대 인덱스이고 i는 테이블이 놓일 위치이다. n+1씩 뛰어야 한다.
        for(int j=0; j<w; j+=(m+1)) {   //w는 열의 최대 인덱스이고 j는 테이블이 놓일 위치이다. m+1씩 뛰어야 한다.
            ++answer;
        }
    }
    cout << answer;
    return 0;
}