#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	while (true)
	{
		map<int, int> m;
		priority_queue<int, vector<int>, greater<int>> pq;

		cin >> N >> M;

		if (N == 0 && M == 0)
		{
			break;
		}

		for (int i = 0; i < N*M; i++)
		{
			int person;
			cin >> person;

			if (m.find(person) == m.end())
			{
				m[person] = 1;
			}
			else
			{
				m[person]++;
			}
		}
		int max = 0;
		int firstPerson;
		map<int, int>::iterator i;
		for (i = m.begin(); i != m.end(); i++)
		{
			if (i->second > max)
			{
				max = i->second;
				firstPerson = i->first;
			}
		}
		m.erase(firstPerson);
		int secondMax=0;
		for (i = m.begin(); i != m.end(); i++)
		{
			if (i->second > secondMax)
			{
				secondMax = i->second;
			}
		}

		for (i = m.begin(); i != m.end(); i++)
		{
			if (i->second == secondMax)
			{
				pq.push(i->first);
			}
		}

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << "\n";
	}
}
