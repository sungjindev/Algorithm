#include <iostream>
#include <stack>
using namespace std;

/*
1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
*/

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0;
    stack<int> s1;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int command=0;
        cin >> command;
        switch(command)
        {
            case 1:
                int x;
                cin >> x;
                s1.push(x);
                break;
            case 2:
                if(!s1.size())
                    cout << "-1" << "\n";
                else {
                    cout << s1.top() << "\n";
                    s1.pop();
                }
                break;
            case 3:
                cout << s1.size() << "\n";
                break;
            case 4:
                if(!s1.size())
                    cout << 1 << "\n";
                else
                    cout << 0 << "\n";
                break;
            case 5:
                if(!s1.size())
                    cout << "-1" << "\n";
                else {
                    cout << s1.top() << "\n";
                }
                break;
        }
    }
    
    return 0;
}