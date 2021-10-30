#include <iostream>
using namespace std;

long long dp[90];

long long Fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    dp[n] = Fibo(n - 1) + Fibo(n - 2);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << Fibo(n);
}