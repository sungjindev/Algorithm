#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char, int> um;
    string answer = "";
    um['R'] = 0;
    um['T'] = 0;
    um['C'] = 0;
    um['F'] = 0;
    um['J'] = 0;
    um['M'] = 0;
    um['A'] = 0;
    um['N'] = 0;
    
    for(int i=0; i<survey.size(); i++) {
        switch(choices[i]) {
            case 1:
                um[survey[i][0]] += 3;
                break;
            case 2:
                um[survey[i][0]] += 2;
                break;
            case 3:
                um[survey[i][0]] += 1;
                break;
            case 5:
                um[survey[i][1]] += 1;
                break;
            case 6:
                um[survey[i][1]] += 2;
                break;
            case 7:
                um[survey[i][1]] += 3;
                break;
        }
    }
    
    if(um['R'] == um['T']) {
        answer += "R";
    } else {
        if(um['R'] > um['T']) {
            answer += "R";
        } else {
            answer += "T";
        }
    }
    
    if(um['C'] == um['F']) {
        answer += "C";
    } else {
        if(um['C'] > um['F']) {
            answer += "C";
        } else {
            answer += "F";
        }
    }
    
    if(um['J'] == um['M']) {
        answer += "J";
    } else {
        if(um['J'] > um['M']) {
            answer += "J";
        } else {
            answer += "M";
        }
    }
    
    if(um['A'] == um['N']) {
        answer += "A";
    } else {
        if(um['A'] > um['N']) {
            answer += "A";
        } else {
            answer += "N";
        }
    }
    
    return answer;
}