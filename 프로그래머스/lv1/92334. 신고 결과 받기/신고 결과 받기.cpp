#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    //일단 report에서 중복 제거
    vector<int> call_count(id_list.size());
    set<string> s1(report.begin(), report.end());
    // unodered_map<string,string> find_caller_map;
    vector<pair<string,string>> caller_callee;
    unordered_map<string,int> name_map;
    for(int i=0; i<id_list.size(); i++) {   //빠른 연산을 위해 언오더드 맵에 이름, 인덱스 저장 
        name_map[id_list[i]] = i;
    }
    
    for(auto it=s1.begin(); it!=s1.end(); ++it) {
        stringstream ss(*it);
        string caller,callee;
        ss >> caller;
        ss >> callee;
        // find_caller_map[callee] = caller;
        caller_callee.push_back(make_pair(caller, callee));
        call_count[name_map[callee]]++;
    }
    
    for(int i=0; i<call_count.size(); i++) {
        if(call_count[i] >= k) {
            for(auto name_index: name_map) {
                if(name_index.second == i) {
                    for(auto cc: caller_callee) {
                        if(cc.second == name_index.first) {
                            answer[name_map[cc.first]]++;
                        }
                    }
                }
            }
        }
    }
    
    
    
    return answer;
}