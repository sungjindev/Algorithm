#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s1;
    for(auto num: nums) {
        s1.insert(num);
    }
    
    answer = min(s1.size(), nums.size()/2);
    
    return answer;
}