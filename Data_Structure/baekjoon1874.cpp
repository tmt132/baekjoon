#include <stack>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	stack<int> st;
	vector<char> vec;

	int i = 1;
	int j = 1;

	while (j <= n)
	{
		int x;
		cin >> x;
		while (i <= n)
		{
			if (!st.empty() && st.top() == x)
			{
				st.pop();
				vec.push_back('-');
				break;
			}
			st.push(i);
			vec.push_back('+');
			i++;
			
		}
		if (!st.empty() && st.top() == x)
		{
			st.pop();
			vec.push_back('-');
		}
		j++;
	}

	if (!st.empty())
	{
		cout << "NO";
	}
	else
	{
		i = 0;
		while (i < vec.size())
		{
			cout << vec[i] << "\n";
			i++;
		}
	}
		
		
}

