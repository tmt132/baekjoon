#include <vector>
#include <iostream>

using namespace std;


char parent[27+'A'];
char left_child[27 + 'A'];
char right_child[27 + 'A'];
vector<char> pre;
vector<char> in;
vector<char> post;
bool pre_visited[27 + 'A'];
bool in_visited[27 + 'A'];
bool post_visited[27 + 'A'];


void preorder(int node)
{
	if (node != '.')
	{
		if (pre_visited[node])
		{
			preorder(left_child[node]);
		}
		else
		{
			pre.push_back(node);
			pre_visited[node] = true;
			preorder(left_child[node]);
			preorder(right_child[node]);

		}
	}
	
}

void inorder(int node)
{
	if (node != '.')
	{
		if (in_visited[node])
		{
			inorder(right_child[node]);
		}
		else
		{
			if (in_visited[left_child[node]])
			{
				in.push_back(node);
				in_visited[node] = true;
				inorder(right_child[node]);
			}
			else
			{
				inorder(left_child[node]);
				in.push_back(node);
				in_visited[node] = true;
				inorder(right_child[node]);
			}

		}
	}

}

void postorder(int node)
{
	if (node != '.')
	{
		if (post_visited[left_child[node]])
		{
			if (post_visited[right_child[node]])
			{
				if (post_visited[node])
				{
					return;
				}
				else
				{
					post.push_back(node);
					post_visited[node] = true;
				}
			}
			else
			{
				postorder(right_child[node]);
				post.push_back(node);
				post_visited[node] = true;
			}

		}
		else
		{
			postorder(left_child[node]);
			postorder(right_child[node]);
			post.push_back(node);
			post_visited[node] = true;

		}
	}

}


int main()
{
	int N;
	cin >> N;
	int i=0;
	while (i < N)
	{
		char parent_temp;
		char left_temp;
		char right_temp;
		cin >> parent_temp >> left_temp >> right_temp;

		parent[left_temp] = parent_temp;
		left_child[parent_temp] = left_temp;

		
		parent[right_temp] = parent_temp;
		right_child[parent_temp] = right_temp;


		i++;
	}

	preorder('A');
	i = 0;
	while (i < pre.size())
	{
		cout << pre[i];
		i++;
	}
	cout << "\n";

	inorder('A');
	i = 0;
	while (i < in.size())
	{
		cout << in[i];
		i++;
	}
	cout << "\n";

	postorder('A');
	i = 0;
	while (i < post.size())
	{
		cout << post[i];
		i++;
	}
	cout << "\n";
}


