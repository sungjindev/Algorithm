#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> weight;
    int temp = 1;
    int sum = 0;
    for(int i=1; 1 ; i *= 3) {
        temp =  3 * i;
        if(sum + temp < n) {
            sum += temp;
            continue;
        }
        else
            break;
    }
    
    while(n > 0) {
        temp = temp/3;
        for(int j=1; j<=3 ; j++) {
            if(sum+temp*j >= n) {
                if(j==3)
                    answer += '4';
                else
                    answer += to_string(j);
                sum -= temp;
                n -= temp*j;
                break;
            }
        }
    }
    
    return answer;
}