#include <iostream>
#include <deque>
using namespace std;

deque<pair<bool, int>> A;

int N;
int K;

int answer = 1;

void rotation()
{
	A.push_front(A.back());
	A.pop_back();
	A[N - 1].first = false;

	for (int i = N - 2; i >= 0; i--)
	{
		if (A[i].first && !A[i + 1].first && A[i + 1].second > 0)
		{
			A[i].first = false;
			A[i + 1].first = true;
			A[i + 1].second--;
		}
	}
	A[N - 1].first = false;

	if (!A[0].first && A[0].second > 0)
	{
		A[0].first = true;
		A[0].second--;
	}

}

int main()
{

	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++)
	{
		int a;
		cin >> a;
		A.push_back(make_pair(false, a));
	}

	while (true)
	{
		rotation();
		int count = 0;
		for (int i = 0; i < 2 * N; i++)
		{
			if (A[i].second == 0)
			{
				count++;
			}
		}
		if (count >= K)
		{
			cout << answer;

			return 0;
		}
		answer++;

	}

}