#include <iostream>
using namespace std;

//n의 최대값은 128이고 2차원 배열이므로 최대 128*128이다. 따라서 board는 128*128 사이즈로 만들어 둘 것이다.
//문제를 보면 굉장히 재귀적인 느낌이 들고, 직전에 풀었던 문제와 사실 매우 똑같은 문제이며
//심지어 이전에는 -1,0,1로 총 3가지로 구분되었던 색상이 여기선 0,1로 2가지로 구분된다고 생각하면 된다.

//알고리즘은 크게 지금 조회하고 있는 종이가 모두 같은 색으로 채워져있는지 검사하는 Check로직과
//이 Check로직을 호출하고 모두 동일한 색이 아니라면 절반의 길이로, 총 4개의 작은 종이로 나누는 oneSecond 재귀 함수로직이 있을 것이다.
//oneSecond 재귀 함수에서는 현재 종이 영역에 대한 Check 로직을 먼저 돌린 다음 만약 모두 같은 색으로 채워져있다면
//count 배열에 적절히 숫자를 증가시켜주면 되고,
//만약 모두 같은 색으로 이루어져 있지 않다면, 총 4가지의 부분 종이 조각으로 나누는 oneSecond 본인을 재귀적으로 호출해주면 된다.
//이때 어차피 oneSecond 안에 check로직을 호출하는 부분이 들어가 있기 때문에 1*1 크기를 가지는 종이에 대한 처리가 알아서 되고
//이 자체가 재귀 함수의 탈출 조건인 Base condition이 될 것이다.

//이 oneSecond 재귀 함수의 매개변수로는 좌상단 좌표의 인덱스 x,y와 해당 종이 영역의 한 변의 길이인 n을 넘겨주면 정사각형 꼴의 종이이므로
//해당 종이 영역 내의 인덱스를 모두 구할 수 있다. check의 파라미터도 마찬가지이다.

int count[2] = {0, };   //인덱스 0은 0으로 채워진 종이의 개수이고 인덱스 1은 1로 채워진 종이의 개수를 담을 것이다.
int board[128][128] = {0,}; //종이에 대한 색상 정보를 담을 2차원 배열이다.

bool check(int x, int y, int n) {
    for(int i=x; i<x+n; ++i) {
        for(int j=y; j<y+n; ++j) {
            if(board[x][y] != board[i][j])
                return false;
        }
    }
    return true;
}

void oneSecond(int x, int y, int n) {
    if(check(x, y, n)) {
        ++count[board[x][y]];
        return;
    }
    
    n  /= 2;    //종이를 4등분 해야되므로 변의 길이를 반절로 변경
    
    oneSecond(x,y,n);
    oneSecond(x+n,y,n);
    oneSecond(x,y+n,n);
    oneSecond(x+n,y+n,n);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    
    for(int i=0; i<n; ++i) {    //지도 생성
        for(int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }

    oneSecond(0,0,n);
    cout << count[0] << "\n" << count[1];
    
    return 0;
}