#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	string ans;
	stack<char> stk;

	int i = 0;
	while (i < str.length())
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ans = ans + str[i];
		}
		else if (str[i] == '(')
		{
			stk.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
			{
				ans = ans + stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!stk.empty() && (stk.top() !='('))
			{
				ans = ans + stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!stk.empty() && (stk.top() != '('))
			{
				ans = ans + stk.top();
				stk.pop();
			}
			stk.pop();
		}

		i++;
	}

	while (!stk.empty())
	{
		ans = ans + stk.top();
		stk.pop();
	}

	cout << ans;

}

