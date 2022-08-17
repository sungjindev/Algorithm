#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int num, temp;
  vector<int> v1;
  cin >> num;

  for(int i=0; i<num; i++) {
    cin >> temp;
    v1.push_back(temp);
  }

  sort(v1.begin(), v1.end());
  cout << v1.front() << " " << v1.back();

  return 0;
}