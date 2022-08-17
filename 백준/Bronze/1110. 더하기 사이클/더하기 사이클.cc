#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count = 0;
    string num,temp;
    cin >> num;
    
    if(num.size() == 1) {
        temp = "0" + num;
        num = temp;
    } else {
        temp = num;
    }
    
    while(true) {
        count++;
        temp = temp[1]+ to_string(((int)(temp[0]-'0') + (int)(temp[1]-'0'))%10);
        if(temp == num)
            break;
    }
    
    cout << count;

    return 0;
}