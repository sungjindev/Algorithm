#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer, count = 0;
    vector<int> index;
    for(int i=0; i<priorities.size(); i++)
        index.push_back(i);
    while(priorities.size() != 0) {
        int tempPriority = priorities[0];
        int tempIndex = index[0];
        priorities.erase(priorities.begin());
        index.erase(index.begin());
        if(tempPriority < *max_element(priorities.begin(), priorities.end())) {
            priorities.push_back(tempPriority);
            index.push_back(tempIndex);
        }
        else {
            count++;
            if(tempIndex == location)
                return answer = count;
        }
    }
}