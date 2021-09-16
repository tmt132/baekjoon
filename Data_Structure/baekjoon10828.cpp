#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	stack<int> st;

	int i;
	i = 0;
	while (i < n)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			st.push(num);
		}
		else if (cmd == "pop")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << st.size() << endl;
		}
		else if (cmd == "empty")
		{
			cout << st.empty() << endl;
		}
		else if (cmd == "top")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << endl;
			}
		}
		i++;
	}
}
