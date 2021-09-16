#include <map>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	double count = 0;
	map<string, double> mp;

	string str;

	while (getline(cin, str))
	{
		if (mp.count(str))
		{
			mp[str]++;
		}
		else
		{
			mp[str] = 1;
		}
		
		count++;
	}

	
	map<string, double>::iterator iter;


	cout << fixed;
	cout.precision(4);
	iter = mp.begin();
	while (iter != mp.end())
	{
		cout << iter->first << " " << iter->second / count * 100 << "\n";
		iter++;
	}



}

