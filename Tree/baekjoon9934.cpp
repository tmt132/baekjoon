#include <vector>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int arr[10][512];
int check[10][512];
queue<int> input;
int k;

void func(int a, int b)
{
	if (input.empty())
	{
		return;
	}
	if (a == k - 1)
	{
		if (check[a][b])
		{
			func(a - 1, b / 2);
			check[a - 1][b / 2] = 1;
		}
		else
		{
			arr[a][b] = input.front();
			input.pop();
			check[a][b] = 1;
			func(a - 1, b / 2);
			check[a - 1][b / 2] = 1;
		}
	}
	else if(a==0)
	{
		if (check[a+1][b*2])
		{
			if (check[a][b])
			{
				func(a + 1, b * 2 + 1);
				check[a + 1][b * 2 + 1]=1;
			}
			else
			{
				arr[a][b] = input.front();
				input.pop();
				check[a][b] = 1;
				func(a + 1, b * 2 + 1);
				check[a + 1][b * 2 + 1]=1;
			}
		}
		else
		{
			func(a + 1, b * 2);
			check[a + 1][b * 2] = 1;
		}
		
	}
	else
	{
		if (check[a][b] && check[a + 1][b * 2] && check[a + 1][b * 2 + 1])
		{
			func(a - 1, b / 2);
			check[a - 1][b / 2] = 1;
		}
		else if(check[a+1][b*2])
		{
			if (check[a][b])
			{
				func(a + 1, b * 2 + 1);
				check[a + 1][b * 2 + 1] = 1;
			}
			else
			{
				arr[a][b] = input.front();
				input.pop();
				check[a][b] = 1;
				func(a + 1, b * 2 + 1);
				check[a + 1][b * 2 + 1] = 1;
			}
		}
		else
		{
			func(a + 1, b * 2);
			check[a + 1][b * 2] = 1;
		}

	}

}

int main()
{
	cin >> k;
	

	int i = 0;
	int temp[1023];
	while (i < pow(2,k)-1)
	{
		cin >> temp[i];
		input.push(temp[i]);
		i++;
	}
	
	func(0, 0);
	i = 0;
	int j = 0;
	while (i < k)
	{
		j = 0;
		while (j < pow(2, i))
		{
			cout << arr[i][j]<<" ";
			j++;
		}
		cout << "\n";
		i++;
	}
	
	
	
}

