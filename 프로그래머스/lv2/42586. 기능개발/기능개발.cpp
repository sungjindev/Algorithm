#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> days;
vector<int> solution(vector<int> progresses, vector<int> speeds);
void calcDays(vector<int> progresses, vector<int> speeds);
vector<int> calcDistributes(vector<int> answer);

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    calcDays(progresses, speeds);
    answer = calcDistributes(answer);
    return answer;
}

void calcDays(vector<int> progresses, vector<int> speeds) {
    for(int i=0; i<progresses.size(); i++) {
        float number = ceil((100.0 - static_cast<float>(progresses[i])) / speeds[i]);
        days.push_back(number);
    }
}

vector<int> calcDistributes(vector<int> answer) {
    int maxDay = 0;
    for(int i=0; i<days.size(); i++) {
        if(maxDay < days[i]) {
            answer.push_back(1);
            maxDay = days[i];
        }
        else
            answer.back()++;
    }   
    return answer;
}