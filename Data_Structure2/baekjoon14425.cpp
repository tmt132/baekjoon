#include <string>
#include <iostream>
#include <map>
using namespace std;


int main()
{
	int n;
	int m;
	cin >> n >> m;
	int result=0;
	map<string, int> mp;

	int i = 0;
	while (i < n)
	{
		string str;
		cin >> str;
		mp.insert({ str,1 });

		i++;
	}

	string* arr = new string[m];

	i = 0;
	while (i < m)
	{
		cin >> arr[i];
		if (mp.find(arr[i]) != mp.end())
		{
			result++;
		}
		i++;
	}

	cout << result;


}

