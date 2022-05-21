#include <iostream>
#include <deque>
using namespace std;

int N, M;
int Map[8][8];
int Answer = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0};

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
        }
    }
}
void bfs()
{
    deque<pair<int, int>> virus;
    int tempMap[8][8];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tempMap[i][j] = Map[i][j];
            if (tempMap[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    while (!virus.empty())
    {
        int x = virus.front().first;
        int y = virus.front().second;

        virus.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            {
                continue;
            }
            if (tempMap[nx][ny] == 0)
            {
                tempMap[nx][ny] = 2;
                virus.push_back(make_pair(nx, ny));
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tempMap[i][j] == 0)
            {
                count++;
            }
        }
    }

    Answer = Answer > count ? Answer : count;
}
void MakeWall(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Map[i][j] == 0)
            {
                Map[i][j] = 1;
                MakeWall(cnt + 1);
                Map[i][j] = 0;
            }
        }
    }
}

int main()
{
    Input();
    MakeWall(0);
    cout << Answer;
}