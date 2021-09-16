#include <string>
#include <iostream>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int i = 0;
	int result = 0;
	int count = 0;
	while (i < str.length())
	{
		if (str[i] == '(')
		{
			count++;
		}
		else if (str[i] == ')' && str[i - 1] == '(')
		{
			count--;
			result = result + count;
		}
		else
		{
			count--;
			result++;
		}
		i++;
	}
	cout << result;
}