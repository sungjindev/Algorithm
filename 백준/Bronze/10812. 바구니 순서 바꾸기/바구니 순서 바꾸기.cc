#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int arr[101];
    for (int i = 1; i <= 100; i++) {
        arr[i] = i;
    }
    int begin, end, mid;
    for (int i = 0; i < m; i++) {

        cin >> begin >> end>> mid;
        int start = begin;  // 입력마다 시작인덱스 저장해서 계속 증가시킴
        int brr[101] = { 0 };
        for (int j = begin;j<mid;j++) {
            brr[j] = arr[j];    // 기존의 값 미리 저장
        }
        int cnt = 0;
        for (int j = mid; j <= end; j++) {
            arr[start] = arr[j];    // 바구니 회전
            start++;    
        }
       
        for (int j = begin; j < mid; j++) {
            arr[start] = brr[j];
            start++;
        }
        
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;

}