#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();   
    for(int i=1; i<size; i++) {
        int temp = 0;
        for(int j=0; j<numbers.size(); j++) {
            if(i & (1 << j)) {
                temp -= numbers[j];
            }
            else {
                temp += numbers[j];
            }
        }
        if(temp == target)
            answer++;
    }
    return answer;
}