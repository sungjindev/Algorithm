#include <iostream>
using namespace std;

//a,b,c의 범위가 int형 최대 이하이므로 int에 담는 것까지는 가능
//근데 a를 2번만 곱해버려도 사실 바로 int형 overflow 발생
//그러므로 long long으로 늘려주고 overflow 발생하지 않도록
//a를 6번 곱하는 걸 예로들어 a를 3번 곱한 값을 제곱해주는 방식으로 재귀를 구현
//즉, a를 b번 곱하는 걸 a를 b/2번 곱한 값에 대한 나머지를 구하고 이를 제곱하여 나머지를 구하여 리턴하기
//이때 b가 짝수이면 그대로 a^(b/2)를 그대로 사용해도 되지만, b가 홀수라면 a를 한번더 곱해줘야함

//    long long value = powAndMod(a,b/2,c)*powAndMod(a,b/2,c)%c;
//만약 위처럼 해주면 동일한 값을 구하기 위해 재귀를 두번이나 반복해서 호춣하기 때문에 굉장히 비효율적이고 시간 초과가 발생한다.
//따라서 long long value = powAndMod(a,b/2,c)를 따로 구해줘야 한다.

long long powAndMod(long long a, long long b, long long c) { //a를 b제곱해서 c로 나눈 나머지를 리턴해주는 재귀 함수
    if(b==1) {
        return a%c;
    }
    
    long long value = powAndMod(a,b/2,c);
    value = value*value%c;

    if(b%2==1)
        value = value * a % c;
    return value;
}

int main(void) {
    long long a,b,c;
    
    cin >> a >> b >> c;
    
    cout << powAndMod(a,b,c);
    
    return 0;
}