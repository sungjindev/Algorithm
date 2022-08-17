#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int head = 0;
    int tail = people.size()-1;
    sort(people.begin(), people.end());
    while(head <= tail) {
        if(people[head] + people[tail] > limit) {
            answer ++;
            tail--;
            continue;
        }
        answer++;
        head++;
        tail--;
    }
    return answer;
}