#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    int weight = 1;
    vector<int> v;
    while(n) {
        v.push_back(n % 3);
        n /= 3;
    }
    
    for(int i=v.size()-1; i>=0; i--) {
        answer += weight * v[i];
        weight *= 3;
    }
    
    return answer;
}