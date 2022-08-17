#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
  int answer = 0;
  sort(citations.begin(), citations.end());
  for (int i = 0; i <= citations.size(); i++)
  {
    int more = citations.size() - (lower_bound(citations.begin(), citations.end(), i) - citations.begin());
    if (i <= more && citations.size() - more <= i)
      answer < i ? answer = i : 1;
  }
  return answer;
}