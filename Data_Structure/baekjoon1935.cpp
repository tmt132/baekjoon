#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	double ans;
	int *arr= new int[n];
	int i = 0;
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}
	stack<double> st;
	int j = 0;
	double a;
	double b;
	while (j < str.length())
	{
		if (str[j]>='A' && str[j]<='Z')
		{
			st.push(arr[str[j]-'A']);
		}
		else if (str[j] == '*')
		{
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			ans = a * b;
			st.push(ans);
		}
		else if (str[j] == '+')
		{
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			ans = a + b;
			st.push(ans);
		}
		else if (str[j] == '/')
		{
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			ans = a / b;
			st.push(ans);
		}
		else if (str[j] == '-')
		{
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			ans = a - b;
			st.push(ans);
		}
		j++;
	}

	ans = st.top();

	cout << fixed;
	cout.precision(2);
	cout << ans;

}

