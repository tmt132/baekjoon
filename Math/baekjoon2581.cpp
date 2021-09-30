#include <iostream>
#include <math.h>
using namespace std;

bool check(int n)
{
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	int max = sqrt(n);
	for (int i = 2; i <= max; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int ansSum = 0;
	int ansMin = -1;

	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		if (check(i) && ansSum == 0)
		{
			ansMin = i;
			ansSum += i;
		}
		else if (check(i))
		{
			ansSum += i;
		}
	}
	if (ansSum == 0)
		cout << "-1";
	else
	{
		cout << ansSum << "\n" << ansMin;
	}
}
