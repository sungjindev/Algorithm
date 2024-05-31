#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//words에 target이 되는 단어가 없으면 변환할 수 없으므로 바로 0을 리턴하자.
//하지만 그것이 전부가 아니다. 단어가 있어도 변환할 수 없을 수도 있으므로 그 이후에 체크하자.

//이 문제는 전형적인 bfs 문제이다.
//begin에서 시작해서 words를 그래프 삼아 참고하여 바꿀 수 있는 경우는 queue에 넣어 관리한다.
//그리고 이에 대한 코스트는 map으로 관리한다.
//begin에서 시작해서 바꿀 수 있는 것들을 모두 바꾸고 방문했으면(queue가 비면) 루프를 탈출하여
//최종 target에 대한 cost를 리턴한다. 만약 해당 target에 대한 key가 map에 생성되어 있지 않았으면 0을 리턴한다.

//나는 words와 begin에 대해서 각각 자기 자신과 알파벳 1개 이하로 차이나는 단어들을 인접 행렬처럼 저장하도록
//map<string, vector<string>> 타입의 adj를 만들어서 관리했다.

map<string, vector<string>> adj;    //begin과 words 각각에 대해 본인과 1개의 알파벳만 차이나는 것들을 저장
map<string,int> visited; //cost를 계산하기 위한 map

void check(string a, string b) {
    int cnt = 0;
    
    if(a==b)
        return;
    
    for(int i=0; i<a.length(); ++i) {
        if(a[i] != b[i]) {
            ++cnt;
        }
    }
    
    if(cnt <= 1) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<string> q1;

    for(auto word: words) {
        check(begin, word); //서로 1개의 알파벳만 차이나는지 검사하고 맞다면 adj에 저장
    }
    
    for(int i=0; i<words.size()-1; ++i) {
        for(int j=i+1; j<words.size(); ++j) {
            check(words[i], words[j]);  //words 내 단어 두개끼리 서로 검사
        }
    }
    
    auto it = find(words.begin(), words.end(), target);
    if(it == words.end())   //words에 target이 포함되어 있지 않은 경우, 불가능하므로 0을 리턴!
        return 0;
    
    q1.push(begin);
    visited[begin] = 0;
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        for(auto v: adj[curr]) {
            if(visited[v] == 0) {
                visited[v] = visited[curr] + 1;
                q1.push(v);
            }
        }
    }
    
    return visited[target];
}