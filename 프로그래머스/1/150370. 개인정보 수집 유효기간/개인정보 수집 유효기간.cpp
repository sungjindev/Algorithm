#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;


unordered_map<string,int> m1;

int calcDay (string date) {
    date[4] = ' ';
    date[7] = ' ';
    stringstream ss(date);
    int year;
    int month;
    int day;
    ss >> year >> month >> day;
    day += ((month*28) + ((year-2000)*12*28));
    return day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // today를 2000년도부터 지난 날짜로 변환
    int todayDate = calcDay(today);
    
    for(auto v: terms) {
        stringstream ss(v);
        string type;
        int period;
        ss >> type >> period;
        m1[type] = period;
    }
    
    for(int i=0; i<privacies.size(); ++i) {
        stringstream ss2(privacies[i]);
        string date;
        string type2;
        ss2 >> date >> type2;
        int day = calcDay(date);
        day += m1[type2]*28;
        if(todayDate>=day) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}