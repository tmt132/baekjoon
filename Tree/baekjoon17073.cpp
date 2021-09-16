#include <vector>
#include <iostream>
using namespace std;

vector<int> vec[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	double W;
	cin >> N >> W;

	int i = 0;
	while (i < N - 1)
	{
		int U;
		int V;
		cin >> U >> V;
		vec[U].push_back(V);
		vec[V].push_back(U);

		i++;
	}
	double leaf=0;
	i = 2;
	while (i <= N)
	{
		if (vec[i].size() == 1)
		{
			leaf = leaf + 1;
		}
		i++;
	}
	cout.precision(11);
	cout << W / leaf;

}

