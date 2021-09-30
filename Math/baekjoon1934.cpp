#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int A, B;
        cin >> A >> B;
        int min = A < B ? A : B;
        int ans1;
        for (int i = min; i>=1; i--)
        {
            if (A % i == 0 && B % i == 0)
            {
                ans1 = i;
                break;
            }
        }
        cout << A * B / ans1 << "\n";
    }
}