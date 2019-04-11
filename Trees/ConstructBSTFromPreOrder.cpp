/* A O(n^2) program for construction of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	node *left;
	node *right;
};

// A utility function to create a node
node* newNode (int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

typedef struct node Node;

int getMinIdx(int* a,int l,int h,int key)
{
    for(int i=l;i<=h;i++)
    {
        if(a[i]>key)
            return i;
    }
    return -1;
}

Node* constructTreeUtil(int* a,int l,int h,int* idx)
{
    if(l>h) return NULL;
    Node* root= newNode(a[(*idx)++]);
    if(l==h) return root;
    int minIdx = getMinIdx(a,l,h,root->data);
    root->left = constructTreeUtil(a,l+1,minIdx-1,idx);
    root->right = constructTreeUtil(a,minIdx,h,idx);
    return root;
}

Node* constructTree(int* a,int n)
{
    int cur = 0;
    return constructTreeUtil(a,0,n-1,&cur);
}

void printInorder(Node* root)
{
    if(root)
    {
        printInorder(root->left);
        cout<<(root->data)<<" ";
        printInorder(root->right);
    }
}

// Driver program to test above functions
int main ()
{
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof( pre ) / sizeof( pre[0] );

	node *root = constructTree(pre, size);

	cout<<"Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}

//This is of n^2 time complexity , refer gfg for O(n) time complexity approach.