#include <iostream>
using namespace std;

int main(void) {
  int num=0;
  cin >> num;
  for(int i=0; i<num; i++) {
    for(int k=1; k+i<num; k++) {
      cout << " ";
    }
    for(int j=0; j<=i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
};