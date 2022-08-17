#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    int i = s.size();
    if(s.size()%2==0) {
        answer += s[i/2-1];
        answer += s[i/2];
    } else {
        answer += s[i/2];
    }
    return answer;
}