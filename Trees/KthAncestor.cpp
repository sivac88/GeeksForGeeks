/* C++ program to calculate Kth ancestor of given node */
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

void populate(Node* root,int parent,unordered_map<int,int>& m)
{
    if(root==NULL) return;
    m[root->data] = parent;
    populate(root->left,root->data,m);
    populate(root->right,root->data,m);
}

int kthAncestor(Node* root,int n,int k,int key)
{
    unordered_map<int,int> m(n);
    populate(root,-1,m);
    int parent;
    do
    {
        parent = m[key];
        k--;
        if(k==0) return parent;
        key = parent;

    }while(parent!=-1);

    return -1;
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 2;
	int node = 5;

	// print kth ancestor of given node
	cout<<kthAncestor(root,5,k,node);
	return 0;
}
