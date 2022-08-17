#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<string> result;

void recursive(vector<string> temp, string i, string num) {
    if(i!="0" || num.length()!=0) {
        num += i;
        result.insert(num);
    }
    temp.erase(find(temp.begin(), temp.end(), i));
    for(string i: temp)
        recursive(temp, i, num);
}

bool isPrimeNumber(string num) {
    int number = stoi(num);
    if(number <= 1)
        return false;
    for(int i=2; i<number; i++) {
        if(number % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<string> nums;
    for(char i: numbers) {
        nums.push_back(to_string(i-48));
    }
    for(string i: nums)
        recursive(nums, i, "");
    for(string i: result) {
        if(isPrimeNumber(i))
            answer++;
    }   
    return answer;
}