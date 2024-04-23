#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 1000000

int a,p;
vector<int> visited(MAX, 0);

int calc(int k) {
    int sum=0;
    while(k > 0) {
        sum += (int)(pow(k%10,p));
        k/=10;
    }
    return sum;
}

void dfs(int k) {
    ++visited[k];
    if(visited[k] >= 3)
        return;
    
    dfs(calc(k));
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> p;
    int answer = 0;
    dfs(a);
    
    for(int i=0; i<MAX; ++i) {
        if(visited[i] == 1) {
            ++answer;
        }
    }
    cout << answer;
    
    return 0;
}