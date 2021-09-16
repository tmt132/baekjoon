#include <iostream>
#include <stack>
#include <string>
using namespace std;

int check(string str)
{
    stack<char> st;
    int j=0;
    while (j < str.length())
    {
        if (str[j] == '(')
        {
            st.push(str[j]);
        }
        else
        {
            if (st.empty())
            {
                return (0);
            }
            else
            {
                st.pop();
            }
        }
        j++;
    }
    return (st.empty());
}

int main()
{
    int t;
    cin >> t;
    int i;
    i = 0;
    while (i < t)
    {
        string str;
        cin >> str;
        if (check(str))
            cout << "YES\n";
        else
            cout << "NO\n";

        i++;
    }
}

