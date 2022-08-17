#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a>b) {
        int c = a;              
        a = b;
        b = c;
    }
    for(int i=a; i<=b; i++) {
        answer += i;
    }
    return answer;
}