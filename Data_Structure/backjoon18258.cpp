﻿#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i=0;
	queue<int> q;
	while (i < n)
	{
		
		string str;
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			q.push(num);

		}
		else if (str == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << endl;
		}
		else if (str == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (str == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << endl;
			}
		}
		else if (str == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << endl;
			}
		}
		i++;
	}
}

