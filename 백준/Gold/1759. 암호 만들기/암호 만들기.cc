#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이 문제는 전형적인 백트래킹 문제이다.
//우선, 알파벳 순으로 정렬되어야 하므로 알파벳 후보들을 입력받은 다음 정렬해서 사용할 것이다.
//또한 백트래킹을 위한 재귀함수에서 원하는 L자리수가 채워지면 최소 한 개의 모음과 최소 두 개의 자음으로 이루어져있는지 확인한 뒤 출력할 것이다.

int l,c;
int arr[26];
vector<char> v1;

void func(int k) {
    if(k == l) {
        int vowel = 0;
        int consonant = 0;
        
        for(int i=0; i<l; ++i) {
            if(v1[arr[i]] == 'a' || v1[arr[i]] == 'e' || v1[arr[i]] == 'i' || v1[arr[i]] == 'o' || v1[arr[i]] == 'u')
                ++vowel;
            else
                ++consonant;
        }
        
        if(vowel >= 1 && consonant >= 2) {
            for(int i=0; i<l; ++i) {
                cout << v1[arr[i]];
            }
            cout << "\n";
        }
        return;
    }
    
    int index = 0;
    if(k != 0) {
        if(arr[k-1] == 25)
            return;
        index = arr[k-1]+1;
    }
    for(;index<c; ++index) {
        arr[k] = index;
        func(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char temp;
    cin >> l >> c;
    for(int i=0; i<c; ++i) {
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    func(0);
    return 0;
}