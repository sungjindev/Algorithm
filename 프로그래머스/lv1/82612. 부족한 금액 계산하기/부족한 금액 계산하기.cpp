using namespace std;

long long solution(int price, int money, int count)
{
    long answer = -1;
    long tprice = (long)price;
    long tmoney = (long)money;
    for(int i=0; i<count; i++) {
        long temp = tprice * (i+1);
        tmoney -= temp;
    }
    if(tmoney >= 0)
        answer = 0;
    else
        answer = tmoney * -1;
    return answer;
}