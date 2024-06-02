#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

//우선 각 장르 별로 곡을 나누어서 map에 담기로 했다.
//map은 map<string,vector<pair<int,int>>> 형식으로 담을 것이고 pair는 각 곡의 플레이 횟수와 고유번호의 쌍이다.
//이렇게 저장한 다음 algorithm의 sort를 custom해서 문제 조건에 맞게 플레이 횟수 내림차순, 동일하면 고유 번호 오름 차순으로 정렬할 것이다.

//그 후 장르별 각각 총 재생 횟수를 구하기 위해 map을 하나 별도로 만들고 custom sort로 map의 value에 따른 내림 차순으로 정렬할 것이다.
//그 순서에 맞춰서 각 장르별로 top2를 뽑아 내면 될 것 같다.
//이때 map을 그대로 value를 기준으로 정렬하는 게 안되므로 별도의 벡터를 만들고 거기에 값을 복사해서 벡터를 정렬시켜줬다.

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}    

bool compare2(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,vector<pair<int,int>>> m1;
    map<string,int> m2;
    vector<pair<string,int>> v1;
    
    for(int i=0; i<genres.size(); ++i) {
        m1[genres[i]].push_back({plays[i],i});
        m2[genres[i]] += plays[i];
    }
    
    for(auto& v: m1) {
        sort(v.second.begin(), v.second.end(), compare);
    }
    
    v1.assign(m2.begin(),m2.end());
    sort(v1.begin(), v1.end(), compare2);
    
    for(auto v: v1) {
        if(m1[v.first].size() == 1) {
            answer.push_back(m1[v.first][0].second);
        } else {
            answer.push_back(m1[v.first][0].second);
            answer.push_back(m1[v.first][1].second);
        }
    }
    
    return answer;
}