#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size()-k;
    int i = 1;
    auto it = number.begin();
    while(answer.size() != size) {
        it = max_element(it, number.end()-(size-i));
        answer += *(it++);
        i++;
    }
    return answer;
}