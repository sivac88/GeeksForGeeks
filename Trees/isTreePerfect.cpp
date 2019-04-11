// C++ program to check whether a given
// Binary Tree is Perfect or not
#include<bits/stdc++.h>

/* Tree node structure */
struct Node
{
	int key;
	struct Node *left, *right;
};


/* Helper function that allocates a new node with the
given key and NULL left and right pointer. */
struct Node *newNode(int k)
{
	struct Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

bool isPerfectUtil(Node* root,int* lvl,int cur)
{
    if(root==NULL) return true;

    if(root->left==NULL && root->right==NULL)
    {
        if((*lvl)==-1) (*lvl) = cur;
        else if((*lvl)!=cur) return false;

        return true;
    }

    if(root->left==NULL || root->right==NULL)
        return false;

    return isPerfectUtil(root->left,lvl,cur+1) && isPerfectUtil(root->right,lvl,cur+1);
}

bool isPerfect(Node* root)
{
    if(root==NULL) return true;
    int leaf_level = -1;
    isPerfectUtil(root,&leaf_level,0);
}

// Driver Program
int main()
{
	struct Node* root = NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);

	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	if (isPerfect(root))
		printf("Yes\n");
	else
		printf("No\n");

	return(0);
}
