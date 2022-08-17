#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int n,x;
  vector<int> v1;
  cin >> n >> x;
  for(int i=0; i<n; i++) {
    int temp = 0;
    cin >> temp;
    if(temp < x)
      v1.push_back(temp);
  }

  for(int i: v1) {
    cout << i << " ";
  }
  return 0;
}