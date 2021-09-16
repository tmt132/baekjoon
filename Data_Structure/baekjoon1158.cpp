#include <iostream>
using namespace std;

int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;

    int* list = new int[n];
    int* ans = new int[n];

    int i;
    i = 0;
    while (i < n)
    {
        list[i] = 0;
        i++;
    }

    i = 0;
    int j;
    int count;
    j = 0;
    count = 1;
    while (j < n)
    {
        if (list[i] == 0 && count == k)
        {
            ans[j] = i + 1;
            count = 1;
            list[i] = 1;
            i++;
            if (i == n)
            {
                i = 0;
            }
            j++;
            continue;
        }
        if (list[i] == 1)
        {
            i++;
            if (i == n)
            {
                i = 0;
            }
            continue;
        }
        count++;
        i++;
        if (i == n)
        {
            i = 0;
        }
    }

    i = 0;
    cout << "<";
    while (i < n - 1)
    {
        cout << ans[i] << ", ";
        i++;
    }
    cout << ans[n - 1];
    cout << ">";
}