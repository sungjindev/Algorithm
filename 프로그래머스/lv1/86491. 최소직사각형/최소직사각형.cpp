#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer=0, min=0, max=0, tempMin=0, tempMax=0;
    for(vector<int> i: sizes) {
        if(i[0] >= i[1]) {
            tempMax = i[0];
            tempMin = i[1];
        } else {
            tempMax = i[1];
            tempMin = i[0];
        }
        tempMax > max ? max = tempMax : 0;
        tempMin > min ? min = tempMin : 0;
    }
    return answer = max * min;
}