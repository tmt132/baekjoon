#include <iostream>
using namespace std;

int N, M;
int Answer;
int MAP[500][500];
bool Visit[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input()
{
    cin >> N >> M;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> MAP[i][j];
        }
    }
}

void DFS(int x, int y, int Sum, int Cnt)
{
    Visit[x][y] = true;

    if (Cnt == 3)
    {
        Answer = Answer > Sum ? Answer : Sum;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N || Visit[nx][ny])
        {
            continue;
        }

        DFS(nx, ny, Sum + MAP[nx][ny], Cnt + 1);
        Visit[nx][ny] = false;
    }
    Visit[x][y] = false;
}

void Shape1(int x, int y) // ㅜ
{
    int temp = MAP[x][y] + MAP[x][y + 1] + MAP[x - 1][y] + MAP[x + 1][y];
    Answer = Answer > temp ? Answer : temp;
}
void Shape2(int x, int y) // ㅗ
{
    int temp = MAP[x][y] + MAP[x][y - 1] + MAP[x - 1][y] + MAP[x + 1][y];
    Answer = Answer > temp ? Answer : temp;
}
void Shape3(int x, int y) // ㅓ
{
    int temp = MAP[x][y] + MAP[x-1][y] + MAP[x][y+1] + MAP[x][y-1];
    Answer = Answer > temp ? Answer : temp;
}
void Shape4(int x, int y) // ㅏ
{
    int temp = MAP[x][y] + MAP[x + 1][y] + MAP[x][y + 1] + MAP[x][y - 1];
    Answer = Answer > temp ? Answer : temp;
}

int main()
{
    Input();

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            DFS(i, j, MAP[i][j], 0);
            if (j+1<N && i-1>=0 && i+1<M)
            {
                Shape1(i, j);
            }
            if (j-1>=0 && i - 1 >= 0 && i + 1 < M)
            {
                Shape2(i, j);
            }
            if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < N)
            {
                Shape3(i, j);
            }
            if (i + 1 < M && j - 1 >= 0 && j + 1 < N)
            {
                Shape4(i, j);
            }
        }
    }

    cout << Answer;
}
