#include <iostream>
using namespace std;

int main(void) {
  int a,b;
  while(1) {
    cin >> a >> b;
    if(!a && !b)
      break;
    cout << a+b << endl;
  }
  return 0;
}