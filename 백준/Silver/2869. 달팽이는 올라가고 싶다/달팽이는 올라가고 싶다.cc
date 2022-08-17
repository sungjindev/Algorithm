#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,v;
    int sum = 0;
    int count = 0;
    cin >> a >> b >> v;
    
    cout << (int)ceil((double)(v-a)/(a-b))+1;
    return 0;
}