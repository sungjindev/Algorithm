#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int i = 0;
    sort(d.begin(), d.end());
    for(i=0; i<d.size(); i++) {
        budget -= d[i];
        if(budget < 0)
            return answer = i;
    }   
    return answer= i;
}