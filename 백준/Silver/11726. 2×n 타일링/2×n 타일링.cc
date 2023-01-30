#include <iostream>
using namespace std;

int fib[1001] = {0,1,2,};

int calc(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    
    if(!fib[n-2])
        fib[n-2] = calc(n-2) % 10007;
    if(!fib[n-1])
        fib[n-1] = calc(n-1) % 10007;

    return fib[n-2] + fib[n-1];
}

int main(void) {
    int n=0;
    cin >> n;
    
    cout << calc(n) % 10007;
    
    return 0;
}