#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int m;
		cin >> m;
		
		priority_queue<int> q1;
		priority_queue<int, vector<int>, greater<int>> q2;
		vector<int> answer;
		int i = 0;
		while (i < m)
		{
			int num;
			cin >> num;
			q1.push(num);
			while (q1.size() > q2.size() + 1)
			{
				int temp;
				temp = q1.top();
				q1.pop();
				q2.push(temp);
			}
			while (!q1.empty() && !q2.empty() && q1.top() > q2.top() )
			{
				int a = q1.top();
				int b = q2.top();
				q1.pop();
				q2.pop();
				q1.push(b);
				q2.push(a);
			}
			
			if (i % 2 == 0 && !q1.empty())
			{
				answer.push_back(q1.top());
			}

			i++;
		}

		cout << (m + 1) / 2 << "\n";
		int j = 0;
		while (j < answer.size())
		{
			cout << answer[j];
			if (j % 9 == 0 && j!=0)
			{
				cout << "\n";
			}
			else
			{
				cout << " ";
			}
			
			j++;
		}
		cout << "\n";
		


	}



}

