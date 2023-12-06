#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    string str1 = to_string(n);
    int arr[9] = {0, };   //여기에서 str1의 각 자리의 탐색하며 얻은 각 숫자의 개수를 저장
    for(auto c: str1) {
        if(c=='6' || c=='9')
            arr[6]++;
        else
            arr[c-'0']++;
    }
    arr[6] = (int)ceil((double)arr[6] / 2);
    cout << *max_element(arr, arr+9);
    
    return 0;
}