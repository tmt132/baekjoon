#include <iostream>
using namespace std;

long long dp[30][30];

long long combi(int m, int n)
{
    if ( n== 0 || m == n)
    {
        return 1;
    }
    if (dp[m][n] != 0)
    {
        return dp[m][n];
    }
    dp[m][n] = combi(m - 1, n - 1) + combi(m - 1, n);
    return dp[m][n];
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;

        cout << combi( m,  n) << "\n";

    }

}