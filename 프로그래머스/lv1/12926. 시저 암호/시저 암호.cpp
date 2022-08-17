#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= 65 && s[i] <= 90)
            s[i] = s[i] + n > 90 ? s[i]+n-91+65 : s[i]+n; 
        else if(s[i] >= 97 && s[i] <= 122)
            s[i] = s[i] + n > 122 ? s[i]+n-123+97 : s[i]+n;
    }
    answer = s;
    return answer;
}