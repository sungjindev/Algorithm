#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesMap;
    for(int i=0; i<clothes.size(); i++) {
        clothesMap[clothes[i][1]]++;
    }
    for(pair<string, int> i: clothesMap) {
        answer *= (i.second+1);
    }
    return --answer;
}