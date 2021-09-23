#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n == 2)
	{
		int n1, n2;
		cin >> n1 >> n2;

		int minVal = min(n1, n2);
		for (int i = 1; i <= minVal; i++)
		{
			if (n1 % i == 0 && n2 % i == 0)
			{
				cout << i << endl;
			}
		}
	}

	if (n == 3)
	{
		int n1, n2,n3;
		cin >> n1 >> n2>>n3;

		int minVal = min(min(n1, n2), n3);
		for (int i = 1; i <= minVal; i++)
		{
			if (n1 % i == 0 && n2 % i == 0 && n3 % i == 0)
			{
				cout << i << endl;
			}
		}
	}
}
