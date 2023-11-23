#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> discount = {10, 20, 30, 40};
vector<int> v1;
vector<int> answer(2,0);

void dfs(vector<vector<int>> users, vector<int> emoticons) {
    if(v1.size() == emoticons.size()) {
        int emoticonPlus = 0;
        int money = 0;
        for(auto user: users) {
            int sum = 0;
            
            for(int i=0; i<emoticons.size(); ++i) {
                if(user[0] <= v1[i]) {
                    sum += (emoticons[i] * (100 - v1[i]) / 100);
                }
            }
            
            if(sum >= user[1]) {
                emoticonPlus++;
            } else {
                money += sum;
            }
        }
        
        if(answer[0] < emoticonPlus) {
            answer[0] = emoticonPlus;
            answer[1] = money;
        } else if(answer[0] == emoticonPlus && answer[1] < money) {
            answer[1] = money;
        }
        return;
    } else{
        for(int i=0; i<discount.size(); i++) {
            v1.push_back(discount[i]);
            dfs(users, emoticons);
            v1.pop_back();
        }
    }   
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {    
    dfs(users, emoticons);
    return answer;
}