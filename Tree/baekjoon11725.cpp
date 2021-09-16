#include <vector>
#include <iostream>
using namespace std;

const int MAX = 100000 + 1;

vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];
int n;

void func(int node)
{
	visited[node] = true;

	int j = 0;
	while (j < tree[node].size())
	{
		int next = tree[node][j];
		if (!visited[next])
		{
			parent[next] = node;
			func(next);
		}
		j++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int i = 0;
	while (i < n - 1)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
		i++;
	}
	func(1);
	i = 2;
	while (i <= n)
	{
		cout << parent[i] << "\n";
		i++;
	}
	return 0;
}


