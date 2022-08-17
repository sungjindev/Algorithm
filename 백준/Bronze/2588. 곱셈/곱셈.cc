#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int a=0;
  int b=0;
  cin >> a >> b;
  string aString = to_string(a);
  string bString = to_string(b);

  cout << a * (bString[2]-48) << endl;
  cout << a * (bString[1]-48) << endl;
  cout << a * (bString[0]-48) << endl;
  cout << a * b << endl;

  return 0;
}