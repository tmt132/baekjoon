#include <deque>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int i = 0;
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}
	deque<pair<int,int>> dq;
	i = 0;
	while (i < n)
	{
		dq.push_back({ i+1,arr[i] });
		i++;
	}
	int num;
	while (!dq.empty())
	{
		num = dq.front().second;
		cout << dq.front().first << " ";
		dq.pop_front();
		if (dq.empty())
		{
			break;
		}
		int j = 0;
		if (num > 0)
		{
			while (j < num-1)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				j++;
			}

		}
		else
		{
			while (j > num)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				j--;
			}
		}
	}
}