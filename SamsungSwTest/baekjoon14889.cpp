#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> S;
bool person[21];
int ans = 100 * 10 * 10;

void dfs(int count, int num)
{
	if (count == N / 2)
	{
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (person[i] == true && person[j] == true)
				{
					start += S[i][j];
				}
				if (person[i] == false && person[j] == false)
				{
					link += S[i][j];
				}
			}
		}

		if (abs(start - link) < ans)
		{
			ans = abs(start - link);
		}
		return;
	}

	for (int i = num; i < N-1; i++)
	{
		person[i] = true;
		dfs(count + 1, i + 1);
		person[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> Si;
		for (int j = 0; j < N; j++)
		{
			int Sij;
			cin >> Sij;
			Si.push_back(Sij);
		}
		S.push_back(Si);
	}

	dfs(0, 0);

	cout << ans;
}
