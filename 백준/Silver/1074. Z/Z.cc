#include <iostream>
#include <cmath>
using namespace std;

//이것도 재귀를 활용해야될 것 같은 느낌이 많이 드는 문제이다.
//N=K일 때 값을 통해 N=K+1일 때 문제에서 원하는 값을 구할 수 있다.

//여기서 중요하게 생각한 패턴은 전체 배열이 주어졌을 때 이걸 총 4사분면으로 나눈다.
//그리고 각 사분면에 방문하는 순서는 이미 정해져 있다. Z자로 방문한다.
//즉, 방문 순서를 조회하고자 하는 지점이 어떤 사분면에 있는지 알면, 그 이전까지 방문한 사분면 내 개수 + 현재 사분면에서 방문 순서
//이걸 더하면 원하는 답을 구할 수 있을 것이다.

//나는 그래서 재귀적으로 계산하는 로직 안에서 어떤 4분면에 위치하는지 구하기 위해서 다음과 같은 로직을 생각했다.
//우선 N의 상관 없이 다음 로직은 모두 적용된다.
//2^(n-1)이 한 변의 절반 길이이므로 r,c를 각각 2^(n-1)로 나눈다. 이때 몫이 짝수인지 홀수인지 여부에 따라 4사분면을 구할 수 있다.

//이렇게 해서 정답을 구할 수 있었지만, 이번에는 좌표평면 상 평행 이동을 이용해서 조금 더 코드를 예쁘게 작성해봤다.


int zTraversal(int n, int r, int c) {
    if(n==0)
        return 0;
    
    int half = 1 << (n-1);
    int boxSize = half * half;
    
    if(r < half && c < half) {
        return zTraversal(n-1, r, c);
    } else if(r < half && c >= half) {
        return boxSize + zTraversal(n-1, r, c-half);
    } else if(r >= half && c < half) {
        return 2*boxSize + zTraversal(n-1, r-half, c);
    }
    return 3*boxSize + zTraversal(n-1, r-half, c-half);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,r,c;
    cin >> n >> r >> c;
    
    cout << zTraversal(n, r, c);
    
    return 0;
}