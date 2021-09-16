
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int val)
{
	if (node == NULL)
	{
		node = new Node;
		node->data = val;
		node->left = NULL;
		node->right = NULL;
	}
	else if (val < node->data)
	{
		node->left = insert(node->left, val);
	}
	else
	{
		node->right = insert(node->right, val);
	}
	return node;
}

void postorder(Node* node)
{
	if (node->left != NULL)
	{
		postorder(node->left);
	}
	if (node->right != NULL)
	{
		postorder(node->right);
	}
	cout << node->data << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	Node* root = NULL;
	int val;
	while (cin >> val)
	{
		if (val == EOF)
		{
			break;
		}
		root = insert(root, val);

	}
	postorder(root);

}

