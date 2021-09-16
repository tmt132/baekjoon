#include <string>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
set<string> ans;
int index[200];
string ret;
int erase[200];

void func_delete(int cur, string str)
{
	if (cur == str.length())
	{
		ans.insert(ret);
		return;
	}
	if (str[cur] == '(')
	{
		erase[index[cur]] = 1;
		func_delete(cur + 1, str);
		erase[index[cur]] = 0;
	}
	if (str[cur]==')' && erase[cur])
	{
		func_delete(cur + 1, str);
	}
	else
	{
		ret = ret + str[cur];
		func_delete(cur + 1, str);
		ret.resize(ret.size() - 1);
	}
}

int main()
{
	string str;
	cin >> str;
	stack<int> bracket;
	int i = 0;
	while (i < str.length())
	{
		if (str[i] == '(')
		{
			bracket.push(i);

		}
		else if (str[i] == ')')
		{
			index[i] = bracket.top();
			index[bracket.top()] = i;
			bracket.pop();
		}
		i++;
	}
	func_delete(0, str);
	ans.erase(str);


	set<string>::iterator iter;
	iter = ans.begin();
	while (iter != ans.end())
	{
		cout << *iter << '\n';
		iter++;
	}



}


