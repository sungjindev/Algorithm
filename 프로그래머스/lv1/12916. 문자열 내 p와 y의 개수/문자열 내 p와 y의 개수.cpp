#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'p' || s[i] == 'P')
            count ++;
        else if(s[i] == 'y' || s[i] == 'Y')
            count --;
    }
    
    if(count != 0)
        answer = false;
    
    return answer;
}