#include <iostream>
#include <map>
using namespace std;

int ans;
multimap<int, int> mp1;

struct Node
{
	int data;
	Node *child[51];

};

Node* insert(Node *node, int parent, int val)
{
	if (parent == -1)
	{
		node = new Node;
		node->data = val;
		int i = 0;
		while (i < 50)
		{
			node->child[i] = NULL;
			i++;
		}
		

	}
	else
	{
		if (node->data != parent)
		{
			int i = 0;
			while (i < 50)
			{
				if (node->child[i] != NULL)
				{
					insert(node->child[i], parent, val);
				}
				i++;
			}
			
			

		}
		else
		{
			int i = 0;
			while (i < 50)
			{
				if (node->child[i] == NULL)
				{
					node->child[i] = new Node;
					node->child[i]->data = val;
					int j = 0;
					while (j < 50)
					{
						node->child[i]->child[j] = NULL;
						j++;
					}
					
					break;
				}
				i++;
			}
			
		}
	}
	return node;
}

Node* remove(Node* node, int rm)
{
	if (node != NULL)
	{
		int i = 0;
		while (i < 50)
		{
			if (node->data == rm)
			{

				node = NULL;
				return node;
			}
			else if (node->child[i] != NULL && node->child[i]->data == rm)
			{
				node->child[i] = NULL;
			}
			else
			{
				if (node->child[i] != NULL)
				{
					remove(node->child[i], rm);

				}
				

			}
			i++;
		}
		
	}
	
	return node;
}

void count(Node* node)
{
	if (node != NULL)
	{
		int i = 0;
		while (i < 50)
		{
			if (node->child[i] != NULL)
			{
				count(node->child[i]);
			}
			i++;
		}

		i = 0;
		int check = 1;
		while (i < 50)
		{
			if (node->child[i] != NULL)
			{
				check = 0;
			}
			i++;
		}
		
		if(check==1)
		{
			ans++;
		}
	}
	

}

int main()
{
	int N;
	cin >> N;

	Node *root=NULL;


	int i = 0;
	while (i < N)
	{
		int parent;
		cin >> parent;
	
		mp1.insert({ parent,i });
		i++;
	}

	while (mp1.size()>0)
	{
		root = insert(root, mp1.begin()->first, mp1.begin()->second);
		mp1.erase(mp1.begin());
	}

	int rm;
	cin >> rm;
	root = remove(root, rm);
	ans = 0;
	count(root);
	cout << ans;
}