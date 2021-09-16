#include <iostream>
#include <vector>
#include <set>


using namespace std;
int main()
{

	vector <pair<int, int>> edges;
	set <int> s;

	int k = 1;
	while (1)
	{
		
		int u;
		int v;
		cin >> u >> v;
		if (u < 0 && v < 0)
		{
			break;
		}
		if (u == 0 && v == 0)
		{
			if (edges.size() + 1 == s.size() || edges.size() == 0)
			{
				cout << "Case " << k << " is a tree." << "\n";
			}
			else
			{
				cout << "Case " << k << " is not a tree." << "\n";

			}

			k++;
			s.clear();
			edges.clear();
			
		}
		else
		{
			s.insert(u);
			s.insert(v);
			edges.push_back({u,v });
		}

		

	}




}
