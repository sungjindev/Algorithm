#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
  int answer = 0;
  int firstTruck = 0;   //다리 위 기준 가장 앞에 있는 트럭 인덱스
  int currentTruck = 0; //앞으로 다리 위로 가장 먼저 올라갈 트럭 인덱스
  queue<int> entryTime; //트럭이 완전히 올라갔을 때 진입 시간을 기준으로 저장
  for (int i = 1; i; i++)
  { //i가 여기서 timer 역할을 함
    if (i == entryTime.front() + bridge_length)
    {
      weight += truck_weights[firstTruck];
      entryTime.pop();
      firstTruck++;
    }
    if (weight - truck_weights[currentTruck] >= 0)
    {
      entryTime.push(i);
      weight -= truck_weights[currentTruck];
      currentTruck++;
      if (currentTruck == truck_weights.size())
        return answer = i + bridge_length;
    }
  }
}