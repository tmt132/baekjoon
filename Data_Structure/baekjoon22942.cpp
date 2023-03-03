#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct info
{
    int pos;
    bool isOpen; // (: true, ): false
    int id;
};

vector<info> v;
stack<int> ids;

bool compare(info a, info b)
{
    return a.pos < b.pos;
}

bool solution()
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].pos == v[i+1].pos)
            return false;
    }
    for (int i = 0; i< v.size(); i++)
    {
        if (v[i].isOpen)
            ids.push(v[i].id);
        else if (v[i].id == ids.top())
            ids.pop();
        else
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0;i < n;i++)
    {
        int x, r;
        cin >>x>>r;
        v.push_back((info){x-r, true, i});
        v.push_back((info){x+r, false, i});
    }

    sort(v.begin(), v.end(), compare);
    cout << (solution() ? "YES" : "NO");
}