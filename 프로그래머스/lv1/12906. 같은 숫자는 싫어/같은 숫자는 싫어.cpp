#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp = -1;
    for(int i: arr) {
        if(temp != i)
            answer.push_back(i);
        temp = i;
    }
    return answer;
}