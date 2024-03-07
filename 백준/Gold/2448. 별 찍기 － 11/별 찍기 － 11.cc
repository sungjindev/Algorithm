#include <iostream>
using namespace std;

const int MAX = 1024 * 3;

int n;
char board[MAX][2*MAX-1];

void fill_star(int x, int y) { //이게 가장 작은 3층짜리 *로 이루어진 삼각형을 채워주는 함수. 이때 해당 삼각형의 가장 상단 좌표를 받는다.
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';
    
    for(int i=y-2; i<=y+2; ++i) {
        board[x+2][i] = '*';
    }
}

void func(int n, int x, int y) {
    if(n == 3) {
        fill_star(x, y);
        return;
    }
    
    n = n/2;    //n을 반으로 줄인다.
    
    func(n, x, y);  //그 후 별 삼각형 세 개가 만들어지는데 이 각 삼각형의 최상단 좌표를 넘겨준다.
    func(n, x+n, y-n);
    func(n, x+n, y+n);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    func(n, 0, n-1);    //가장 꼭대기 삼각형의 윗 좌표와 함께 n을 넘겨줌
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<2*n-1; ++j) {
            if(board[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
    
    return 0;
}