#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  vector<int> v1;
  int num, temp;
  cin >> num;
  for(int i=0; i<num; i++) {
    cin >> temp;
    v1.push_back(temp);
  }
  sort(v1.begin(), v1.end());
  for(int i: v1) {
    cout << i << endl;
  }
  return 0;
}