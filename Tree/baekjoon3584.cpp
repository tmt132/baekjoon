#include <iostream>
#include <vector>
using namespace std;
vector<int> parent[10001];
bool visited[10001];
int answer;

void solve(int node2)
{
	if (visited[node2])
	{
		answer = node2;
		return;
	}
	if (parent[node2].size())
	{
		solve(parent[node2][0]);
	}
}

void visit(int node1)
{
	visited[node1] = true;
	if (parent[node1].size())
	{
		visit(parent[node1][0]);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int i = 0;
	while (i < T)
	{
		int N;
		cin >> N;

		int j = 0;
		while (j < N - 1)
		{
			int A, B;
			cin >> A >> B;
			parent[B].push_back(A);
			j++;
		}
		int node1, node2;
		cin >> node1 >> node2;
		visit(node1);
		solve(node2);
		cout << answer<<"\n";
		parent->clear();
		int k = 1;
		while (k <= N)
		{
			visited[k] = false;
			k++;
		}
		k = 1;
		while (k <= N)
		{
			parent[k].clear();
			k++;
		}
		i++;
	}


}


