#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> originalArray = array;
    vector<int> answer;
    for(int i=0; i<commands.size(); i++) {
        sort(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        answer.push_back(array[commands[i][0]+commands[i][2]-2]);
        array = originalArray;
    }
    return answer;
}