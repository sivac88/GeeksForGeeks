/* C++ program to find distance between n1 and n2 using
one traversal */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

Node* findLCA(Node* root,int n1,int n2,int* ans,bool *visited1,bool* visited2,int cur)
{
    if(root==NULL)
        return NULL;
    if(root->key == n1)
    {
        *ans = cur;
        *visited1 = true;
        return root;
    }
    if(root->key == n2)
    {
        *ans = cur;
        *visited2 = true;
        return root;
    }

    int l=0,r=0;

    Node* left = findLCA(root->left,n1,n2,&l,visited1,visited2,cur+1);
    Node* right = findLCA(root->right,n1,n2,&r,visited1,visited2,cur+1);

    if(left && right)
    {
        *ans = l+r-(2*cur);
        return root;
    }

    if(left)
    {
        *ans = l;
        return left;
    }

    *ans = r;
    return right;
}

int findLevel(Node* lca,int n1,int level)
{
    if(lca==NULL)
        return 0;
    if(lca->key == n1)
        return level;

    int ans = 0;

    if((ans=findLevel(lca->left,n1,level+1)) != 0)
        return ans;

    return findLevel(lca->right,n1,level+1);
}

int findDistance(Node* root,int n1,int n2)
{
    int ans=0;
    bool visited1=false,visited2=false;
    Node* lca= findLCA(root,n1,n2,&ans,&visited1,&visited2,0);
    if(visited1 && visited2)
        return ans;
    if(visited1)
        return findLevel(lca,n2,0);
    return findLevel(lca,n1,0);
}


int main()
{
	// Let us create binary tree given in the
	// above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}
