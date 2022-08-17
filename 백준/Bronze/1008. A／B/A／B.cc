#include <iostream>
using namespace std;

int main(void) {
    cout << fixed;
    cout.precision(10);
    long double n1, n2;
    cin >> n1 >> n2;
    cout << n1/n2;
    
    return 0;
}