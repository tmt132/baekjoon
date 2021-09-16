#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n2) < abs(n1))
		{
			return true;
		}
		else if (abs(n2) == abs(n1))
		{
			if (n2 < n1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else {
			return false;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int i = 0;
	int x;
	priority_queue<int, vector<int>, cmp> pq;
	while (i < n)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";

			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			
		}
		else
		{
			pq.push(x);
		}
		i++;
	}




}

