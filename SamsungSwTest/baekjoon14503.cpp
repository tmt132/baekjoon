#include <iostream>
using namespace std;

int N, M; // 방의 크기
int r, c; // 좌표
int dir; // 방향

// 왼쪽 위쪽이 (0, 0)
int room[50][50]; // 0이면 공간, 1이면 벽
int visited[50][50]; // 0이면 청소안됨, 1이면 청소됨

// 북, 동, 남, 서
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void input()
{
    cin>>N>>M;
    cin>>r>>c>>dir;

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            int state;
            cin>> state;
            room[i][j] = state;
        }
    }
}

void dfs(int r, int c, int d, int sum)
{
    for (int i = 0;i < 4;i++)
    {
        int nd = (d-i+3)%4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if (nr < 0 || nc <0 || nr >= N || nc >= M || room[nr][nc] == 1)
            continue;

        if (visited[nr][nc] == 0 && room[nr][nc] == 0)
        {
            visited[nr][nc] = 1;
            dfs(nr, nc, nd, sum + 1);
        }
    }

    int backIdx = d < 2 ? d+2 : d-2;
    int backR = r + dr[backIdx];
    int backC = c + dc[backIdx];

    if (backR < 0 || backC <0 || backR >= N || backC >= M)
        return;

    if (room[backR][backC] ==1)
    {
        cout<<sum;
        exit(0);
    }
    dfs(backR, backC, d, sum);
}

int main()
{
    input();
    
    visited[r][c] = 1;
    dfs(r,c,dir,1);
    
    return 0;
}