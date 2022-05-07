#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int N;

vector<int> T;
vector<int> P;

void dfs(int day, int pay);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t, p;
		cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}

	dfs(0, 0);
	cout << answer;
}

void dfs(int day, int pay)
{
	if (day == N)
	{
		if (pay > answer)
		{
			answer = pay;
		}
		return;
	}

	dfs(day + 1, pay); // day일에 상담X
	if (day + T[day] <= N)
	{
		dfs(day + T[day], pay + P[day]); // day일에 상담O
	}
}