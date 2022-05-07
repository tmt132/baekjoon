#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	vector<int> A;
	int B, C;
	cin >> N;
	long long answer = N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		if (A[i] >= B)
		{
			answer += (A[i] - B) / C;
			if ((A[i] - B) % C > 0)
				answer++;
		}
	}

	cout << answer;
}