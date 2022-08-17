#include <string>
#include <vector>
using namespace std;



vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    string temp;
    for(int i=0; i<strings.size()-1; i++) {
        for(int j=i+1; j<strings.size(); j++) {
            if(strings[i][n] > strings[j][n]) {
                temp = strings[j];
                strings[j] = strings[i];
                strings[i] = temp;
            }
            else if(strings[i][n] == strings[j][n]) {
                if(strings[i].compare(strings[j]) > 0) {
                    temp = strings[j];
                    strings[j] = strings[i];
                    strings[i] = temp;
                }
            }
        }
    }
    answer = strings;
    return answer;
}