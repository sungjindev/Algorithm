#include <iostream>
using namespace std;

int main(void) {
    int h,m;
    int add;
    scanf("%d %d", &h, &m);
    scanf("%d", &add);
    m += add;
    if(m >= 60) {
        int temp = m/60;
        h += temp;
        m = m%60;
    }
    if(h >= 24)
        h -= 24;
    printf("%d %d", h, m);
    return 0;
}