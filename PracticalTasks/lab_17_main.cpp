#include <iostream>
using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
};

tree* create(tree*& root, int data)
{
	if (!root)
	{
		root = new tree;
		root->data = data;
		root->left = 0;
		root->right = 0;
	}
	else
	{
		if (data < root->data)
			root->left = create(root->left, data);
		else
			root->right = create(root->right, data);
	}
	return root;
}

void print(tree* root, int l = 0)
{
	if (root != NULL)
	{
		print(root->right, l + 1);
		cout.width(l * 4);
		cout << root->data << endl;
		print(root->left, l + 1);
	}
}

void del(tree** node)
{
	if (*node != NULL)
	{
		del(&(*node)->left);
		del(&(*node)->right);
		delete* node;
		*node = NULL;
	}
}

void find_del(tree* root, int key)
{
	if (root == NULL)
		return;
	tree** node = NULL;
	if (root->left && root->left->data == key)
		node = &root->left;
	else
		if (root->right && root->right->data == key)
			node = &root->right;
	if (node)
	{
		delete* node;
		*node = NULL;
	}
	else
		find_del(root->data < key ? root->right : root->left, key);
}

tree rand_tree(tree** root)
{
	for (int i = 0; i < 10; i++)
		create(*root, rand() % 100);
	return **root;
}

int main()
{
	tree* root = NULL;
	int key = 0;
	rand_tree(&root);
	print(root);
	cout << "Enter key: ";
	cin >> key;
	find_del(root, key);
	print(root);
	del(&root);
	return 0;
}