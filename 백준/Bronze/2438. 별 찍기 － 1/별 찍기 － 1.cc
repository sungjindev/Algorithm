#include <iostream>
using namespace std;

int main(void) {
  int num=0;
  cin >> num;
  for(int i=0; i<num; i++) {
    for(int j=0; j<=i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
};