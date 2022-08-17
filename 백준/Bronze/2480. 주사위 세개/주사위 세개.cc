#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> v1(6,0);
    int a;
    int money;
    for(int i=0; i<3; i++) {
        scanf("%d", &a);
        v1[a-1]++;
    }
    auto it = max_element(v1.begin(), v1.end());
    if(*it == 3) {
        money = 10000+(it-v1.begin()+1) * 1000;
        printf("%d", money);
    }
    else if(*it == 2) {
        money = 1000+(it-v1.begin()+1) * 100;
        printf("%d", money);
    }
    else {
        for(int i=5; i>=0; i--) {
            if(v1[i] == 1) {
                money = (i+1) * 100;
                printf("%d", money);
                return 0;
            }
        }
    }
    
    return 0;
}