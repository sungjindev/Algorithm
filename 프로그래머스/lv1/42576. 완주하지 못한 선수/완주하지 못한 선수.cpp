#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(),participant.end(), [](string a, string b) {
        return a<b;
    });
    sort(completion.begin(),completion.end(), [](string a, string b) {
        return a<b;
    });
    for(int i=0; i<completion.size(); i++) {
        if(completion[i] != participant[i]) {
            string answer = participant[i];
            return answer;
        }
    }   
    string answer = participant.back();
    return answer;
}