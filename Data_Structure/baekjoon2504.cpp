#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int ans=0;
	int temp;
	stack<char> stk;
	int i = 0;
	while (i<str.length())
	{
		if (stk.empty())
		{
			temp = 1;
		}
		if (str[i] == '(') 
		{
			stk.push(str[i]);
			temp = temp * 2;
		}
		else if (str[i] == '[')
		{
			stk.push(str[i]);
			temp = temp * 3;

		}
		else if (str[i] == ')' && (stk.empty() || stk.top() != '('))
		{
			ans = 0;
			break;
		}

		else if (str[i] == ']' && (stk.empty() || stk.top() != '['))
		{
			ans = 0;
			break;
		}
		else if (str[i] == ')')
		{
			if (str[i-1] == '(')
			{
				ans = ans + temp;
				stk.pop();
			}
			else
			{
				stk.pop();
			}
			temp /= 2;


		}
		else if (str[i] == ']')
		{
			if (str[i - 1] == '[')
			{
				ans = ans + temp;
				stk.pop();
			}
			else
			{
				stk.pop();
			}
			temp /= 3;


		}

		i++;
	}
	if (!stk.empty())
		ans = 0;
	cout << ans;
}