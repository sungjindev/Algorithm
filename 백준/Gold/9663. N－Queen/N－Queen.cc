#include <iostream>
using namespace std;

//이 문제는 전형적인 백트래킹 문제이다.
//여기서 중요한 아이디어는 퀸을 놓을 수 있는 위치를 어떻게 효율적으로 판단하느냐이다.
//나는 이를 위해 isUsed배열을 총 3개 만들어서 각각이 열에 대해서, 우상단 대각선, 우하단 대각선 각각에 대해
//방문 여부를 true/false로 저장하도록 했다.
//행에 대해서 검사하지 않는 이유는 당연하게도 행에는 1개의 퀸만 놓을 수 있기 때문이다.

//그리고 우상단 대각선은 x+y(행과 열의 합)이 일치하면 같은 대각선상에 놓여있는 것이고
//우하단 대각선은 x-y+(n-1) 이 일치하면 같은 대각선에 놓여있는 것이다. 여기서 n-1을 더해준 이유는 isUsed 배열의 인덱스가 음수가 되는걸 막기 위해서이다.

bool isUsed1[14];
bool isUsed2[27];   //n이 최대가 14일 때 최대 대각선 개수는 2n-1이다.   이건 우상단 대각선
bool isUsed3[27];   //이건 우하단 대각선

int n;
int cnt;

void func(int k) {  //k가 현재 입력해야될 행 번호이다
    if(k==n) {
        ++cnt;
        return;
    }
    
    for(int i=0; i<n; ++i) {    //여기서 i가 열의 번호이다.
        if(isUsed1[i] || isUsed2[k+i] || isUsed3[k-i+(n-1)])
            continue;
        
        isUsed1[i] = true;
        isUsed2[k+i] = true;
        isUsed3[k-i+(n-1)] = true;
        func(k+1);
        isUsed1[i] = false;
        isUsed2[k+i] = false;
        isUsed3[k-i+(n-1)] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    func(0);
    cout << cnt;
    
    return 0;
}