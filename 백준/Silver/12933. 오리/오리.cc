#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    string str1;
    int duckCount = 0;
    map<char,int> m1 = {{'q',0}, {'u',1}, {'a',2}, {'c',3}, {'k',4}}; //문자와 인덱스 넘버를 쉽게 매핑시켜주기 위해서 생성
    cin >> str1;
    
    vector<int> v1; //q가 들어올 때 마다 v1에 0이 push_back되며 벡터 내의 값들 0,1,2,3,4는 각각 q,u,a,c,k를 의미한다.
    //즉 해당 흐름에 맞지 않으면 -1 발생시키고 str1 탐색하면서 k에 도달하면 duck count 1개 늘려주고 배열에서 지워주기
    // 그런데 주의할 점이 duck count를 늘려주기 전에 배열의 원소의 개수를 세서 duck count보다 크면 
    // 동시간에 v1.size()만큼의 오리는 있어야만 하므로 duck count의 최솟값이 v1.size()가 되어야 한다.
    // 따라서 duck count = v1.size()를 해줘야 한다.
    // 탐색이 끝나면 벡터 내 원소가 1개라도 존재하면 -1 리턴하고 duck count 출력
    
    for(int i=0; i<str1.size(); i++) {
        if(m1[str1[i]] == 0) {
            v1.push_back(0);
        } else {
            auto it = find(v1.begin(),v1.end(),m1[str1[i]]-1);
            if(it == v1.end()) {
                cout << "-1";
                return 0;
            } else {
                (*it)++;
                if(*it == 4) {
                    if(v1.size() > duckCount) {
                        duckCount = v1.size();
                        v1.erase(it);
                    } else {
                        v1.erase(it);
                    }
                }
            }
        }
    }
    
    if(!v1.size())
        cout << duckCount;
    else
        cout << "-1";
    
    return 0;
}