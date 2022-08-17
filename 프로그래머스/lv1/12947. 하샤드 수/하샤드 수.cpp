#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int originalX = x;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    (originalX % sum) ? answer = false : answer = true;
    return answer;
}