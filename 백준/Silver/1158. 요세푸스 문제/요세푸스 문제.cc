#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    
    list<int> li1;
    vector<int> result;
    list<int>::iterator it;
    
    for(int i=1; i<=n; i++) {
        li1.push_back(i);
    }
    
    for(it = li1.begin(); li1.size() != 0; ) {
        for(int j=0; j<k-1; j++) {
            if(it == --li1.end()) {
                it = li1.begin();
            } else {
                ++it;
            }
        }
        result.push_back(*it);
        it = li1.erase(it);
        if(it == li1.end()) //iterator가 li1.end()-1 일때 erase하면 iterator가 li1.end()가 되버려서 문제 발생하여 추가해줌
            it = li1.begin();
    }
    
    for(int z=0; z<result.size(); z++) {
        if(z == 0)
            cout << "<";
        if(z != result.size()-1)
            cout << result[z] << ", ";
        else
            cout << result[z] << ">";
    }
    
    return 0;
}