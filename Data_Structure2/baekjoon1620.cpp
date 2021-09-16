#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int m;
	cin >> n >> m;
	map<string, int> mp1;
	string *mp2= new string[n];

	int i = 0;
	while (i < n)
	{
		char name[21];
		cin >> name;
		mp1.insert({ name, i });
		mp2[i] = name;

		i++;
	}

	i = 0;
	while (i < m)
	{
		char name[21];
		cin >> name;
		if (name[0] >= '0' && name[0] <= '9')
		{
			cout << mp2[atoi(name)-1]<< '\n';
		}
		else
		{
			cout << mp1[name] + 1 << '\n';
		}
		i++;
	}



}

