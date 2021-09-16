#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

bool visited[10001];
vector< pair<int, int> > node[10001];

int ans = 0;
int end_point = 0;

void dfs(int point, int length)
{
	if (visited[point])
	{
		return;
	}
	visited[point] = true;
	if (ans < length)
	{
		ans = length;
		end_point = point;
	}
	int i = 0;
	while (i < node[point].size())
	{
		dfs(node[point][i].first, length+ node[point][i].second);
		i++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int i = 0;
	while (i < n - 1)
	{
		int parent, child, length;
		cin >> parent >> child >> length;
		node[parent].push_back({ child,length });
		node[child].push_back({ parent,length });

		i++;
	}

	dfs(1, 0);
	ans = 0;
	memset(visited, false, sizeof(visited));
	dfs(end_point, 0);
	cout << ans;
}