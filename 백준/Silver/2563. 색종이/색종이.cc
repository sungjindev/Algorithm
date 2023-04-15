#include <iostream>
using namespace std;

int main(void) {
    int paper[100][100] = {0,}; //100*100 도화지를 이차원 배열로 구현
    //원래 기존 도화지 조건이라면 101개씩 인덱스를 가져야 하는 것이 맞지만
    //100개로 줄인 이유는 [0][0]원소가 0이 아닌 값을 가진다면 [0][0]을 꼭짓점으로 가지는 1*1 정사각형을 가진다고 정하기 위해서이다.
    //이때 row랑 x좌표계, column과 y좌표계를 매핑시킨다.
    //x,y 좌표계가 시계 방향으로 90도 회전한 것이라고 이해하면 되고, 당연스럽게도 면적은 같을 것이다.
    int n=0;
    int a,b;
    int area=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        for(int x=a; x<a+10; x++) {
            for(int y=b; y<b+10; y++) {
                if(!paper[x][y]) {
                    area++;
                    paper[x][y] = 1;
                }
            }
        }
    }
    cout << area;
    
    return 0;
}