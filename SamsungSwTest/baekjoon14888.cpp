#include <vector>
#include <iostream>

using namespace std;

int N;
vector<int> A;
vector<int> op;

int maxAns = -1000000000;
int minAns = 1000000000;

void dfs(int index, int num)
{
	if (index == N - 1)
	{
		if (num > maxAns)
		{
			maxAns = num;
		}
		if (num < minAns)
		{
			minAns = num;
		}
		return;
	}

	if (op[0] > 0)
	{
		op[0]--;
		dfs(index + 1, num + A[index+1]);
		op[0]++;
	}
	if (op[1] > 0)
	{
		op[1]--;
		dfs(index + 1, num - A[index+1]);
		op[1]++;
	}
	if (op[2] > 0)
	{
		op[2]--;
		dfs(index + 1, num * A[index+1]);
		op[2]++;
	}
	if (op[3] > 0)
	{
		op[3]--;
		dfs(index + 1, num / A[index+1]);
		op[3]++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < 4; i++)
	{
		int op_num;
		cin >> op_num;
		op.push_back(op_num);
	}

	dfs(0, A[0]);

	cout << maxAns << "\n" << minAns;
}