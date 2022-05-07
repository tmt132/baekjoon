#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct STUDENT
{
	int Num;
	int Friends[4];
};
struct POSITION
{
	int x;
	int y;
	int NearlyEmpty;
	int NearlyFriend;
};

vector<STUDENT> Student;
int likeFriends[401][4];

int MAP[21][21];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool Cmp(POSITION A, POSITION B)
{
	if (A.NearlyFriend > B.NearlyFriend)
	{
		return true;
	}
	if (A.NearlyFriend == B.NearlyFriend)
	{
		if (A.NearlyEmpty > B.NearlyEmpty)
		{
			return true;
		}
		if (A.NearlyEmpty == B.NearlyEmpty)
		{
			if (A.y < B.y)
			{
				return true;
			}
			if (A.y == B.y)
			{
				if (A.x < B.x)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}

int answer = 0;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int Num;
		cin >> Num;

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Student.push_back({ Num, {a,b,c,d} });
		likeFriends[Num][0] = a;
		likeFriends[Num][1] = b;
		likeFriends[Num][2] = c;
		likeFriends[Num][3] = d;

		vector<POSITION> Pos;

		for (int x = 1; x <= N; x++)
		{
			for (int y = 1; y <= N; y++)
			{
				if (MAP[x][y] != 0)
				{
					continue;
				}

				int Empty = 0;
				int Friend = 0;
				for (int j = 0; j < 4; j++)
				{
					int nx = x + dx[j];
					int ny = y + dy[j];
					if (nx <= 0 || ny <= 0 || nx >= N+1 || ny >= N+1)
					{
						continue;
					}

					int near = MAP[nx][ny];
					if (near == 0)
					{
						Empty++;
					}
					else if (near == a || near == b || near == c || near == d)
					{
						Friend++;
					}
				}
				Pos.push_back({x,y,Empty,Friend});
			}
		}

		sort(Pos.begin(), Pos.end(), Cmp);
		MAP[Pos[0].x][Pos[0].y] = Num;
	}

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			int count = 0;

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx <= 0 || ny <= 0 || nx >= N + 1 || ny >= N + 1)
				{
					continue;
				}

				int near = MAP[nx][ny];

				for (int k = 0; k < 4; k++)
				{
					if (near == likeFriends[MAP[x][y]][k])
					{
						count++;
					}
				}
			}
			if (count == 1)
			{
				answer += 1;
			}
			if (count == 2)
			{
				answer += 10;
			}
			if (count == 3)
			{
				answer += 100;
			}
			if (count == 4)
			{
				answer += 1000;
			}
		}
	}

	cout << answer;
}
