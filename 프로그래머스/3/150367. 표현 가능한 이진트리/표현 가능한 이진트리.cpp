#include <string>
#include <vector>
#include <iostream>
using namespace std;

//핵심 알고리즘: 우선 주어진 숫자를 2진수로 바꾼다. 그 이후 총 3가지 케이스에 대해서 검사를 한다. 첫번째 케이스는 2진수 그자체, 두번째 케이스는 앞에 0을 붙인 2진수, 마지막 케이스는 뒤에 0을 붙인 2진수이다. 우선 이 3가지 케이스에 대해서 2진수의 길이가 (2^n)-1 꼴이 나오는지를 검사한다. 왜냐하면 포화 이진 트리가 되어야 하기 때문이다. 그 이후 홀수 번째 인덱스의 값이 모두 1인지 검사하면 끝! 모두 1이어야만 자식 노드를 가지는 노드들이 실제 존재하기 때문에 처음에 주어진 트리가 이진 트리일 수 있다.
// 아니다! 위처럼 하면 1000 일 때만 해도 반례가 존재한다. 그게 아니고 핵심 알고리즘은!!! (2^n)-1이 될 수 있게 2진수 앞에 0을 가득 채워주고 중앙값이 1인지 체크한다. 왜냐하면 중앙값이 무조건 포화이진트리에서 루트 노드가 될테니까, 그 후 왼쪽 서브트리와 오른쪽 서브트리를 나눠서 분할 정복(올바른지 체크)한다! 올바른지 체크하는 것은 일단 부모 노드가 0이 아닌지 체크하는 것이다. 부모 노드가 0이 아니어야만 트리가 될 수 있다. 하지만 예외적으로 부모 노드가 0이더라도 그 아래 하위 노드들이 모두 0이라면 가능하다. 이걸 체크하면 된다.

//생각해보니 가뜩이나 숫자들도 크고 원소들도 많은데 이진수를 그때마다 계속 반복적으로 구하기엔 너무 시간이 많이 들 거 같아서, bfs처럼 queue를 활용해서 memorization 하려고 한다.

//하지만 다시 생각해보면 위처럼하면 오히려 10^15 번 연산하는 루프를 통해 memorization 해줘야 되기 때문에 무조건 시간 초과가 발생한다. 다시 생각해보면 이진법 전환이 필요한 numbers의 최대 개수는 1만개이고 각각 가질 수 있는 최대값은 10^15=대략 2^50정도 이므로 이걸 2로 나누면서 2진수를 얻어내는 걸로 계산을 하면 50만번 정도의 연산만 하면 되므로 이게 올바른 방법이다.

string calcDigit(long long number) {
    string digitStr = "";
    while(number) {
        digitStr = to_string(number % 2LL) + digitStr;
        number /= 2LL;
    }
    return digitStr;
}

string makeFullDigit(string digitStr) {
    for(int i=2; ; i*=2) {
        if(i-1 >= digitStr.size()) {
            while((i-1)-digitStr.size()!=0) {
                digitStr = "0" + digitStr;
            }
            break;
        }
    }
    return digitStr;
}

bool checkAllZero(string str1) {
    if(str1.find("1") == string::npos)
        return true;
    else
        return false;
}

bool checkBinaryTree(string digitStr) {
    if(digitStr.size()==1 || checkAllZero(digitStr))
        return true;
    
    int centIndex = digitStr.size()/2;
    string leftTree = digitStr.substr(0,centIndex);
    string rightTree = digitStr.substr(centIndex+1);
    
    if(digitStr[centIndex] == '1' && checkBinaryTree(leftTree) && checkBinaryTree(rightTree))
        return true;
    else
        return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
   
    for(auto number: numbers) {
        string digitStr = calcDigit(number);
        digitStr = makeFullDigit(digitStr);
        if(!checkBinaryTree(digitStr)) {
            answer.push_back(0);
        } else {
            answer.push_back(1);
        }
    }
    
    return answer;
}