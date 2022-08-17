#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.top() < K) {
        if(pq.size() == 1) {
            return -1;
        }
        int mix = pq.top();
        pq.pop();
        pq.push(mix + pq.top()*2);
        pq.pop();
        answer++;
    }
    return answer;
}