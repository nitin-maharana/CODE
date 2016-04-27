/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Delete a node from BST.

#include <iostream>

using namespace std;

struct node
{
	node *left;
	int val;
	node *right;
};

node* insert(node *root, int val)
{
	if(root == nullptr)
	{
		root = new node();
		root->val = val;
		root->left = root->right = nullptr;

		return root;
	}

	if(val > root->val)
		root->right = insert(root->right, val);
	else
		root->left = insert(root->left, val);

	return root;
}

void traverse(node *root)
{
	if(root == nullptr)
		return;

	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);

	return;
}

node* getMax(node *root)
{
	while(root->right)
		root = root->right;

	return root;
}

node* deleteNode(node *root, int val)
{
	if(root == nullptr)
		return root;

	if(val > root->val)
		root->right = deleteNode(root->right, val);
	else if(val < root->val)
		root->left = deleteNode(root->left, val);
	else
	{
		node *temp;

		if(root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if(root->left == nullptr)
		{
			temp = root->right;
			delete root;
			root = temp;
		}
		else if(root->right == nullptr)
		{
			temp = root->left;
			delete root;
			root = temp;
		}
		else
		{
			temp = getMax(root->left);
			root->val = temp->val;
			root->left = deleteNode(root->left, temp->val); 
		}
	}

	return root;
}

//Assuming it is always present.
node* findNode(node *root, int val)
{
	if(root->val == val)
		return root;

	if(val < root->val)
		return findNode(root->left, val);
	else
		return findNode(root->right, val);
}

//Assume it is always present.
int inorderSuccessor(node *root, int val)
{
	node *p = findNode(root, val);

	if(p->right)
	{
		p = p->right;

		while(p->left)
			p = p->left;

		return p->val;
	}

	node *result = root;
	node *curr = root;

	while(curr != p)
	{
		if(p->val < curr->val)
		{
			result = curr;
			curr = curr->left;
		}
		else
			curr = curr->right;
	}

	return result->val;
}

int main(void)
{
	node *root;
	root = nullptr;

	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 12);
	root = insert(root, 20);

	cout << "Before Deletion: ";
	traverse(root);
	cout << endl;

	root = deleteNode(root, 10);

	cout << "After Deletion: ";
	traverse(root);
	cout << endl;

	cout << "Inorder Successor of 7: ";
	cout << inorderSuccessor(root, 7) << endl;
	
	return 0;
}