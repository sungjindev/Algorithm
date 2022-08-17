#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();
    int test = 0;
    for(int i=1; i<=s.length()/2; i++) {
        string temp = "";
        int count = 1;
        int tempAnswer = s.length();
        
        for(int j=0; j+i<=s.length(); j += i) {
            test++;
            if(temp != "" && temp == s.substr(j,i))
                count++;
            else {
                if(count != 1) {
                    tempAnswer = tempAnswer - (i*count-(i+1));
                    if(10<=count && count<=99)
                        tempAnswer += 1;
                    else if(100<=count && count <=999)
                        tempAnswer += 2;
                    else if(count == 1000)
                        tempAnswer += 3;
                    count = 1;
                }
            }
            temp = s.substr(j,i);
        }
        
        if(count != 1) {
            tempAnswer = tempAnswer - (i*count-(i+1));
            if(10<=count && count<=99)
                tempAnswer += 1;
            else if(100<=count && count <=999)
                tempAnswer += 2;
            else if(count == 1000)
                tempAnswer += 3;
        }
        
        if(tempAnswer < answer)
            answer = tempAnswer;
    }
    
    cout << test;
    return answer;
}