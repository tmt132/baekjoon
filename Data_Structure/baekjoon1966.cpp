#include <queue>
#include <iostream>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	int idx = 0;
	while (idx < tc)
	{
		int n;
		int m;
		cin >> n;
		cin >> m;
		int* arr = new int[n];
		int j = 0;
		while (j < n)
		{
			cin >> arr[j];
			j++;
		}
		queue<pair<int,int>> q;
		queue<int> qp;

		j = 0;
		while (j < n)
		{
			q.push({ j,arr[j] });
			j++;
		}

		int i = 0;
		j = 0;
		int temp;
		while (i < n)
		{
			j = i + 1;
			while (j < n)
			{
				if (arr[i] < arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
				j++;
			}
			i++;
		}

		j = 0;
		while (j < n)
		{
			qp.push(arr[j]);
			j++;
		}
		int count = 0;
		int check = 0;
		int k;
		while (!q.empty())
		{
			k = 0;
			check = 0;
			while (k < qp.size())
			{
				if (q.front().second < qp.front())
				{
					check = 1;
					break;
				}
				qp.push(qp.front());
				qp.pop();
				k++;
			}
			if (check)
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				if (q.front().first==m)
				{
					break;
				}
				q.pop();
				qp.pop();
				count++;
			}
		}
		cout << count+1 << "\n";
		idx++;
	}

}