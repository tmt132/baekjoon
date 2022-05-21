#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
int MAP[100][100];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, char>> DirectionInfo;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		MAP[row-1][col-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		DirectionInfo.push_back(make_pair(x, c));
	}
}

int GetDirection(int currentDirection, char c)
{
	if (c == 'L')
	{
		if (currentDirection == 0) return 3;
		else if (currentDirection == 1) return 2;
		else if (currentDirection == 2) return 0;
		else if (currentDirection == 3) return 1;
	}
	else if (c == 'D')
	{
		if (currentDirection == 0) return 2;
		else if (currentDirection == 1) return 3;
		else if (currentDirection == 2) return 1;
		else if (currentDirection == 3) return 0;
	}
}

void Solution()
{
	deque<pair<int, int>> Snake;

	// 뱀의 머리 위치
	int x = 0;
	int y = 0;

	// 뱀의 방향
	int d = 0;

	// 현재 시간
	int Time = 0;

	// DirectionInfo의 인덱스
	int Idx = 0;

	Snake.push_back(make_pair(x, y));
	MAP[x][y] = 2;

	while (true)
	{
		Time++;

		x = x + dx[d];
		y = y + dy[d];

		if (x < 0 || y < 0 || x >= N || y >= N || MAP[x][y] == 2)
		{
			break;
		}
		else if (MAP[x][y] == 0)
		{
			MAP[x][y] = 2;
			MAP[Snake.back().first][Snake.back().second] = 0;
			Snake.pop_back();
			Snake.push_front(make_pair(x, y));
		}
		else if (MAP[x][y] == 1)
		{
			MAP[x][y] = 2;
			Snake.push_front(make_pair(x, y));
		}

		if (Idx < DirectionInfo.size())
		{
			if (Time == DirectionInfo[Idx].first)
			{
				d = GetDirection(d, DirectionInfo[Idx].second);
				Idx++;
			}
		}
	}
	cout << Time;
}

int main()
{
	input();
	Solution();
}
