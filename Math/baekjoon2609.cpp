#include <iostream>
using namespace std;

int main()
{
	int n1, n2;
	cin >> n1 >> n2;

	int ans1, ans2;

	int max = n1 > n2 ? n1 : n2;
	int min = n1 < n2 ? n1 : n2;

	for (int i = min; i >= 1; i--)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			ans1 = i;
			break;
		}
	}

	for (int i = max; true; i++)
	{
		if (i % n1 == 0 && i % n2 == 0)
		{
			ans2 = i;
			break;
		}
	}

	cout << ans1 << "\n" << ans2;
}

