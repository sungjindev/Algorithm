#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool visited[10001];
bool flag = false;

void back(int k, string start) {
    answer.push_back(start);
    
    if(k == ticket.size()) {
        flag = true;
        return;
    }
    
    for(int i=0; i<ticket.size(); ++i) {
        if(ticket[i][0] == start && !visited[i]) {            
            visited[i] = true;
            back(k+1, ticket[i][1]);
            
            if(flag)
                return;
            
            visited[i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    
    back(0, "ICN");
    
    return answer;
}