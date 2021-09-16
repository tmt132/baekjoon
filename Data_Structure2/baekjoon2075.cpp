#include <queue>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue< int, vector<int>, greater<int> > pq;

	int n;
	cin >> n;

	int i = 0;
	int j = 0;

	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			int x;
			cin >> x;
			pq.push(x);
			if (pq.size() > n)
			{
				pq.pop();
			}

			j++;
		}

		i++;
	}

	cout << pq.top();

}

