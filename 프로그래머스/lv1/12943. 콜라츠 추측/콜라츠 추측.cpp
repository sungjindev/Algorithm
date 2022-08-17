#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long number = num;
    while(number != 1) {
        if(answer == 500)
            return answer = -1;
        number = number%2 ? number*3+1 : number/2;
        answer++;
    }
    return answer;
}