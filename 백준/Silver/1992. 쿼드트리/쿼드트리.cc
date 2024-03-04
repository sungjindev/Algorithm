#include <iostream>
#include <string>
using namespace std;

//이 문제 역시 직전에 풀었던 문제들과 매우 닮아있다.
//이전에 풀었던 일반적인 재귀 문제들과 다른 차이점이라고 하면 결과값을 단순히 카운팅하는 것에 그치는 것이 아니고
//string format에서 ()와 같이 괄호를 열고 닫으며 반환해줘야 한다는 점이다.
//하지만 이 문제도 결국 이전 문제와 다를 것이 없는 게 괄호가 열리고 닫히는 흐름이 재귀의 흐름과 동일하기 때문이다.
//따라서 이전에 풀었던 oneSecond 재귀 함수가 시작되면 괄호를 열어주고 끝날 때 괄호를 닫아주는 방식으로 구현하면 된다.

//여기서 사소하지만 주의해야할 점은 이 문제의 input이 공백으로 구분 없이 이어서 들어온다는 것이다.
//따라서 쉽게 받으려면 char형으로 받아야한다. 그리고 char형을 string형에 이어 붙일 땐 그냥 + 연산 활용하면 된다.

string answer = "";

char board[64][64] = {0, };

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
    if(check(x,y,n)) {
        answer = answer + board[x][y];
        return;
    }
    
    n /= 2;
    
    answer += "(";
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            oneSecond(x+i*n, y+j*n, n);
        }
    }
    answer += ")";
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=0;
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }
    
    oneSecond(0, 0, n);
    cout << answer;
    
    return 0;
}