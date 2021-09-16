#include <queue>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	queue<int> q;
	int i = 1;
	while (i <= n)
	{
		q.push(i);
		i++;
	}
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();

}

