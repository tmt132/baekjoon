#include <stack>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int i = 0;
	int* arr = new int[n];
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}
	stack<pair<int,int>> stk;
	

	int* ans = new int[n];

	ans[0] = 0;
	stk.push({ 1,arr[0] });
	i = 1;
	
	while (i < n)
	{
		while (!stk.empty() && stk.top().second < arr[i])
		{
			stk.pop();
		}
		
		if (stk.empty())
		{
			ans[i] = 0;
		}
		else
		{
			ans[i] = stk.top().first;
		}

		stk.push({ i + 1,arr[i] });

		i++;
	}

	i = 0;
	while (i < n)
	{
		cout << ans[i] << " ";
		i++;
	}
}