#include <iostream>
using namespace std;

int cycle(int N)
{
	int leftNum = N / 10;
	int rightNum = N % 10;

	int newRightNum = (leftNum + rightNum) % 10;
	int newLeftNum = rightNum;

	return newLeftNum * 10 + newRightNum;
}

int main()
{
	int N;
	cin >> N;

	int ans = 0;
	int newNum = N;

	while (true)
	{
		newNum = cycle(newNum);
		ans++;
		if (newNum == N)
			break;
	}
	cout << ans;
}

