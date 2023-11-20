#include <string>
#include <queue>
#include <vector>

using namespace std;

// int로는 오버플로우 발생하므로 long long 사용하기
// 여기서 핵심은 while문 탈출 조건이다. q1에 있는 것이 q2로 옮겨지고 다시 처음 q1 상태로 돌아오기까지의 횟수가 최대 횟수 (즉, 4n)

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1=0;
    long long sum2=0;
    int count=0;
    queue<int> q1,q2;
    
    for(int i=0; i<queue1.size(); ++i) {
        sum1 += queue1[i];
        sum2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    while(count <= queue1.size()*4) {
        if(sum1 == sum2) {
            return count;
        } else if(sum1 > sum2) {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
            count++;
        } else {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
            count++;
        }
    }
    return -1;
}