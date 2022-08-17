#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if(sqrt(n) - (int)sqrt(n) == 0.0)
        answer = pow(sqrt(n)+1,2);
    else answer = -1;
    return answer;
}