#include <iostream>
using namespace std;

int main(void)
{
  int x,y;
  cin >> x >> y;
  if(x>0) {
    if(y>0) {
      cout << "1";
    } else if(y<0) {
      cout << "4";
    }
  } else if(x<0) {
    if(y>0) {
      cout << "2";
    } else if(y<0) {
      cout << "3";
    }
  }
  return 0;
}