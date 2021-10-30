#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int max5 = n / 5;
    for (int i = max5; i >= 0; i--)
    {
        if ((n - i * 5) % 3 == 0)
        {
            cout << i + (n - i * 5) / 3;
            return 0;
        }

    }
    cout << -1;
    return 0;
}