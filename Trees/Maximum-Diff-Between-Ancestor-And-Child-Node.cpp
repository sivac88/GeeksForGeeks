//https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
// C++ program to find maximum difference between node
// and its ancestor
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* To create a newNode of tree and return pointer */
struct Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

int maxDiffUtil(Node* root,int* ans)
{
    if(root==NULL)
        return INT_MAX;

    int minValue = min(maxDiffUtil(root->left,ans),maxDiffUtil(root->right,ans));

    *ans = max(*ans,root->key - minValue);

    return min(root->key,minValue);
}

int maxDiff(Node* root)
{
    int ans = INT_MIN;
    maxDiffUtil(root,&ans);
    return ans;
}

// Driver program to test above functions
int main()
{
	// Making above given diagram's binary tree
	Node* root;
	root = newNode(8);
	root->left = newNode(3);

	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	root->right = newNode(10);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);

	printf("Maximum difference between a node and"
		" its ancestor is : %d\n", maxDiff(root));
}
