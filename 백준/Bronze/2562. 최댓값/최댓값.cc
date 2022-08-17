#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  vector<int> v1;
  int temp;
  for(int i=0; i<9; i++) {
    cin >> temp;
    v1.push_back(temp);
  }

  cout << *max_element(v1.begin(), v1.end()) << endl << max_element(v1.begin(), v1.end()) - v1.begin() + 1;
  return 0;
}