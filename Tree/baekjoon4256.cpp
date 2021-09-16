#include <vector>
#include <iostream>
using namespace std;

vector<int> preorder;
vector<int> inorder;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int i = 0;
	while (i < T)
	{
		int n;
		cin >> n;
		int j = 0;
		while (j < n)
		{
			int num;
			cin >> num;
			preorder.push_back(num);
			j++;
		}
		j = 0;
		while (j < n)
		{
			int num;
			cin >> num;
			inorder.push_back(num);
			j++;
		}



		i++;
	}
}

