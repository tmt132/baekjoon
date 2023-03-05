#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int findRoot(map<int, vector<int>> treeMap)
{
    map<int, bool> checkMap;

    for (auto t : treeMap)
        for (auto el : t.second)
            checkMap[el] = true;

    int root = 0;
    for (auto t : treeMap)
        if (!checkMap[t.first])
            root = t.first;

    return root;
}

bool bfs(map<int, vector<int>> treeMap)
{
    int root = findRoot(treeMap);

    map<int, bool> visitedMap; // 들어오는 간선이 존재하는지 확인
    visitedMap[root] = true; // root는 들어오는 간선이 없으나 유효한 노드이므로 true

    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < treeMap[parent].size(); i++)
        {
            int child = treeMap[parent][i];
            if (visitedMap[child]) // 이미 들어오는 간선이 존재
                return false;
            visitedMap[child] = true;
            q.push(child);
        }
    }

    for (auto t : treeMap)
    {
        if (!visitedMap[t.first])
            return false;
        for (auto el : t.second)
        {
            if (!visitedMap[el])
                return false;
        }
    }

    return true;
}

int main()
{
    int k = 1;

    while (true)
    {
        map<int, vector<int>> treeMap;

        while (true)
        {
            int u, v;
            cin >> u >> v;

            if (u==-1 && v==-1)
                return 0;
            if (u == 0 && v == 0)
                break;

            treeMap[u].push_back(v);
        }

        if (bfs(treeMap))
            cout<<"Case "<<k<<" is a tree.\n";
        else
            cout<<"Case "<<k<<" is not a tree.\n";

        k++;
    }
}