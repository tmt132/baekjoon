#include <map>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int tc;
	cin >> tc;
	int i = 0;
	while (i < tc)
	{
		map<int, int> pq1;

		int k;
		cin >> k;
		int j = 0;
		while (j < k)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I')
			{
				pq1[n] = pq1[n] + 1;
			}
			else if (c == 'D')
			{
				if (!pq1.empty())
				{
					if (n == 1)
					{
						if (pq1.rbegin()->second == 1)
						{
							pq1.erase(--pq1.end());
						}
						else
						{
							pq1.rbegin()->second = pq1.rbegin()->second - 1;
						}
					}
					else if (n == -1)
					{
						if (pq1.begin()->second == 1)
						{
							pq1.erase(pq1.begin());
						}
						else
						{
							pq1.begin()->second = pq1.begin()->second - 1;
						}
					}
				}
			}





			j++;
		}

		if (pq1.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << pq1.rbegin()->first << " " << pq1.begin()->first << "\n";
		}

		i++;
	}


}

