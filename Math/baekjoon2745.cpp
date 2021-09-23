#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	string N;
	int B;
	cin >> N>> B;

	int ans = 0;
	for (int i=0; i < N.length(); i++)
	{
		if (N[i] >= 'A' && N[i] <= 'Z')
		{
			ans = ans + (N[i] - 'A' +10) * pow(B, N.length()-1 - i);
		}
		else
		{
			ans = ans + (N[i] - '0') * pow(B, N.length()-1 - i);
		}
	}
	cout << ans;
}