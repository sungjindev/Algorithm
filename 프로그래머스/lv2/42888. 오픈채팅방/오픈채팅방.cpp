#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;  //map의 first가 uid, second가 nickname
    string uid = "";
    string name = "";
    string result = "";
    char* str_buff = new char[1000];

    for(int i=0; i < record.size(); i++) {
        strcpy(str_buff, record[i].c_str());
        char* tok = strtok(str_buff, " ");
        if(string(tok) == "Change" || string(tok) == "Enter") {
            tok = strtok(nullptr, " ");
            uid = string(tok);
            tok = strtok(nullptr, " ");
            name = string(tok);
            m[uid] = name;
        }
    }

    for(int i=0; i < record.size(); i++) {
        result = "";
        strcpy(str_buff, record[i].c_str());
        char* tok = strtok(str_buff, " ");
        if(string(tok) == "Enter") {
            tok = strtok(nullptr, " ");
            result += m[string(tok)];
            result += "님이 들어왔습니다.";
            answer.push_back(result);
        }
        else if(string(tok) == "Leave") {
            tok = strtok(nullptr, " ");
            result += m[string(tok)];
            result += "님이 나갔습니다.";
            answer.push_back(result);
        }
    }    

    return answer;
}