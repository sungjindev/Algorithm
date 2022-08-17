#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string answer = "";
    int day = 0;
    for(int i=0; i<a-1; i++) {
        day += month[i];
    }
    day += b-1;
    switch(day % 7) {
        case 0:
            answer += "FRI";
            break;
        case 1:
            answer += "SAT";
            break;
        case 2:
            answer += "SUN";
            break;
        case 3:
            answer += "MON";
            break;
        case 4:
            answer += "TUE";
            break;
        case 5:
            answer += "WED";
            break;
        case 6:
            answer += "THU";
            break;
    }
    return answer;
}