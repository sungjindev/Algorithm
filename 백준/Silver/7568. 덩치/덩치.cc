#include <iostream>
#include <vector>
using namespace std;

//우선 Algorithm의 sort()를 사용하고 comparator를 커스텀해서 문제의 요구사항을 구현해야겠다 생각했다.
//이렇게 하고난 다음 정렬은 되었는데 문제 조건에 맞게 순위를 구해줘야 되는데 
//나는 정렬을하고 난 뒤, 정렬된 배열을 0번째 인덱스부터 순차 탐색하면서 순위를 구해주기로 했다.
//이때 이전 값을 들고 다음 인덱스 원소로 넘어가면서 이전 값보다 키와 몸무게 둘 다 작으면 등수를 현재 인덱스번호를 활용해서
//등수를 변경하고 그걸 바탕으로 입력해주기로 했다.
//따라서, 정렬 후 순차 탐색 할 때 등수에 대한 변수를 함께 가지고 있어야하며, 키와 몸무게 모두 작은 원소를 만나게 되면 
//그 시점에 등수를 변경해줄 것이다.

//하지만, 위처럼 풀면 안된다!!!
//왜냐하면 
//6
//20 50
//19 49
//18 48
//50 20
//49 19
//48 18
//이런 반례가 있는데, 이것의 정답은 1 2 3 1 2 3 이다. 이게 기준이 되는게 몸무게, 키 두 개에 대해서 나보다 큰 것들의 개수를 찾아야 되는 것인데
//이렇게 되다보니 마땅한 정렬 기준 1개로 정렬을 시킬 수가 없다.
//따라서 풀이를 수정해서, 각각의 원소를 완전 탐색하면서 해당 원소보다 몸무게,키 모두 큰 원소의 개수를 구하고 거기에 +1해서 등수를 정해주기로 했다.

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,weight,height;
    vector<pair<int,int>> v1;
    
    cin >> n;
    
    for(int i=0; i<n; ++i) {
        cin >> weight >> height;
        v1.push_back({weight,height});
    }
    
    for(int i=0; i<v1.size(); ++i) {
        int currWeight = v1[i].first;
        int currHeight = v1[i].second;
        int cnt = 0;
        
        for(int j=0; j<v1.size(); ++j) {
            if(currWeight < v1[j].first && currHeight < v1[j].second) {
                ++cnt;
            }
        }
        cout << cnt+1 << " ";
    }
    
    return 0;
}
