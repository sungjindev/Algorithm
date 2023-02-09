#include <iostream>

using namespace std;

long long d2(long long N)		//2의 개수
{
	long long cnt = 0;
	for (long long i = 2; i <= N; i *= 2)
		cnt += N / i;
	return cnt;
}

long long d5(long long N)		//5의 개수
{
	long long cnt = 0;
	for (long long i = 5; i <= N; i *= 5)
		cnt += N / i;
	return cnt;
}

int main(void)
{
	long long n, m;
	cin >> n >> m;
	cout << min(d5(n) - d5(m) - d5(n - m), d2(n) - d2(m) - d2(n - m));	//조합 공식
}