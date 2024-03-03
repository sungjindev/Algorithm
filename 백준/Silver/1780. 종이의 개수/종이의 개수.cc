#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//일단 이 문제 재귀적인 느낌이 물씬 든다.
//N도 3^7이 최대니까 최대 배열의 원소 개수는 3^14이다. 이는 4782969이므로 int 기준 약 4.78*4 = 약 19.12MB이다. 메모리적으로도 문제 없다.

//일단 재귀 함수는 배열의 가로 길이를 넘겨받고 이 배열의 1/3의 길이를 구해서 총 9등분을 하고
//각 등분마다 모두 같은 수로 이루어져있는지 체크하고 그렇지 않다면 재귀적으로 본인의 함수를 호출하는 방식으로 구현하면 될 것이다.
//여기서 Base conditon, 즉 재귀의 탈출 조건은 배열의 한변의 길이를 나타내는 n이 1일 때 일 것이다. 이땐 그냥 return 해버리면 된다.

//재귀 함수에서는 배열의 길이인 n을 받도록 했다. 그리고 처음 배열 정보는 따로 넘겨주지 않고 전역 변수로 해결
//근데 생각해보니 이렇게하면 어떤 조각(어떤 인덱스)들이 타겟이 되는지 알 수 없기 때문에 pair를 활용해서 좌상단 꼭짓점 좌표와
//좌상단 좌표를 x,y로 넘겨줌과 동시에 종이의 변의 길이인 n도 넘겨주기로 결정

vector<vector<int>> paper;

int count[3] = {0,};    //-1, 0, 1로 채워진 종이 수를 카운팅하기 위한 배열

bool check(int x, int y, int n) {   //x,y 좌표로 시작해서 만들어지는 n길이의 종이 영역 내 모두 같은 원소로 이루어져있는지 체크
    for(int i=x; i<x+n; ++i) {
        for(int j=y; j<y+n; ++j) {
            if(paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

void countPaper(int x, int y, int n) {  //좌상단 좌표와 종이의 길이만 넘겨주면 해당 종이 영역의 모든 인덱스에 접근 가능!
    if(check(x,y,n)) {
        ++count[paper[x][y]+1];
        return;
    }
    
    n /= 3; //변의 길이를 1/3로 쪼개는 것
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            countPaper(x+i*n, y+j*n, n);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    cin >> n;
    paper.assign(n, vector<int>(n, 0));  //n*n 꼴의 배열을 생성
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> paper[i][j];
        }
    }
    
    countPaper(0, 0, n);
    
    for(int i=0; i<3; ++i) {
        cout << count[i] << "\n";
    }

    return 0;
}