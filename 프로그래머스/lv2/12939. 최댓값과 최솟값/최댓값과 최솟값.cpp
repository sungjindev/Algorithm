#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    int num = 0, min = 0, max = 0;
    stringstream ss(s);
    ss >> num;
    min = max = num;
    
    while(ss >> num) {
        if(num<min)
            min = num;
        if(num>max)
            max = num;
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}