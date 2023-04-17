//x,y 좌표의 각각의 최솟값, 최댓값을 구하기만하면 되므로 set을 활용했습니다.
//set을 활용하면 중복 좌표도 제거할 수 있을 뿐만 아니라 정렬되기 때문에 구현하기 편합니다.
//이 문제에서 주의할 점으로는 점의 개수가 충분하지 못하면, 즉 x,y 좌표 각각이 2종류 이상이 되지 못하면 직사각형을 이룰 수 없습니다.
#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n=0;
    int x,y;
    set<int> xSet;
    set<int> ySet;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        xSet.insert(x);
        ySet.insert(y);
    }
    
    if(xSet.size()<2 || ySet.size()<2) {    //x,y좌표 각각이 서로 다른 2종류 이상의 숫자로 이루어져있는지 검사
        cout << 0;
    } else {
        int minX = *xSet.begin();
        int maxX = *xSet.rbegin();
        int minY = *ySet.begin();
        int maxY = *ySet.rbegin();
        cout << (maxX-minX) * (maxY-minY);
    }
    
    return 0;
}