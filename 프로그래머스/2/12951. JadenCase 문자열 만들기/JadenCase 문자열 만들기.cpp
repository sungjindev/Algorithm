#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char before = s[0];
    
    s[0] = toupper(s[0]);
    
    for(int i=1; i<s.length(); ++i) {
        if(before == ' ') {
            s[i] = toupper(s[i]);
            before = s[i];
        } else {
            s[i] = tolower(s[i]);
            before = s[i];
        }
    }
    answer = s;
    return answer;
}