#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person1 = {1,2,3,4,5};
    vector<int> person2 = {2,1,2,3,2,4,2,5};
    vector<int> person3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> count = {0,0,0};
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == person1[i%5])
            count[0]++;
        if(answers[i] == person2[i%8])
            count[1]++;
        if(answers[i] == person3[i%10])
            count[2]++;
    }
    int max = *max_element(count.begin(), count.end());
    for(int i=0; i<count.size(); i++) {
        if(max == count[i])
            answer.push_back(i+1);
    }
    return answer;
}