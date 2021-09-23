#include <iostream>
using namespace std;
int main()
{
	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int tired = 0;
	int work = 0;
	for (int i = 1; i <= 24; i++)
	{
		if (tired + A <= M)
		{
			tired += A;
			work += B;
		}
		else if (tired - C >= 0)
		{
			tired -= C;
		}
	}
	cout << work;
}
