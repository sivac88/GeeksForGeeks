//https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
/* C++ Program to convert an aribitary
binary tree to a tree that hold
children sum property */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;

	/* Constructor that allocates a new node
	with the given data and NULL left and right
	pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void increment(node* root,int diff)
{
    if(root==NULL)
        return;

    if(root->left)
    {
        root->left->data += diff;
        increment(root->left,diff);
    }
    else if(root->right)
    {
        root->right->data += diff;
        increment(root->right,diff);
    }
}

void convertTree(node* root)
{
    if(root==NULL)
        return;

    convertTree(root->left);
    convertTree(root->right);

    int left=0,right=0;
    if(root->left)
        left = root->left->data;
    if(root->right)
        right = root->right->data;

    int diff = left+right-(root->data);

    if(diff>=0)
        root->data = root->data + diff;
    else
       increment(root,-diff);
}

/* Given a binary tree,
printInorder() prints out its
inorder traversal*/
void printInorder(node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout<<node->data<<" ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver code */
int main()
{
	node *root = new node(50);
	root->left = new node(7);
	root->right = new node(2);
	root->left->left = new node(3);
	root->left->right = new node(5);
	root->right->left = new node(1);
	root->right->right = new node(30);

	cout << "\nInorder traversal before conversion: " << endl;
	printInorder(root);

	convertTree(root);

	cout << "\nInorder traversal after conversion: " << endl;
	printInorder(root);
	return 0;
}

// This code is contributed by rathbhupendra
