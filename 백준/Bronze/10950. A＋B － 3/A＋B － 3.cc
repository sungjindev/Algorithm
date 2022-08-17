#include <iostream>
using namespace std;

int main(void) {
  int num,a,b;
  cin >> num;
  for(int i=0; i<num; i++) {
    cin >> a >> b;
    cout << a+b << endl;
  }
  return 0;
}