#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for(int i: arr) {
        if(i % divisor == 0)
            answer.push_back(i);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}