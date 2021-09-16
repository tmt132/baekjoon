#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;


	int i = 0;
	while (i < N-1)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);

		i++;
	}

	int q;
	cin >> q;

	i = 0;
	while (i < q)
	{
		int t, k;
		cin >> t >> k;
		if (t == 2)
		{
			cout << "yes\n";
		}
		else
		{
			if (vec[k].size() >= 2)
			{
				cout<< "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
		i++;
	}



}

