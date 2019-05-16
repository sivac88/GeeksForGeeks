// C++ program to find path length
// having maximum number of bends
#include <bits/stdc++.h>
using namespace std;

// structure node
struct Node {
	int key;
	struct Node* left;
	struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node();
	node->left = NULL;
	node->right = NULL;
	node->key = key;

	return node;
}

void findMaxBendsUtil(Node* root,bool isLeft,int* bends,int* no_of_nodes,int cur_bends,int cur_nodes)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        if(cur_bends > (*bends))
        {
            *bends = cur_bends;
            *no_of_nodes = cur_nodes  + 1;
        }
        return;
    }
    if(isLeft)
    {
        findMaxBendsUtil(root->left,true,bends,no_of_nodes,cur_bends,cur_nodes+1);
        findMaxBendsUtil(root->right,false,bends,no_of_nodes,cur_bends+1,cur_nodes+1);
    }
    else
    {
        findMaxBendsUtil(root->left,true,bends,no_of_nodes,cur_bends+1,cur_nodes+1);
        findMaxBendsUtil(root->right,false,bends,no_of_nodes,cur_bends,cur_nodes+1);
    }
}

int findMaxBends(Node* root)
{
    int left_max_bends = -1,right_max_bends=-1,left_nodes = 0,right_nodes=0;
    findMaxBendsUtil(root->left,true,&left_max_bends,&left_nodes,0,0);
    findMaxBendsUtil(root->right,false,&right_max_bends,&right_nodes,0,0);
    if(left_max_bends>right_max_bends)
        return 1+left_nodes;
    return 1+right_nodes;
}

// Driver code
int main()
{
	/* Constructed binary tree is
	10
	/ \
	8 2
	/ \ /
	3 5 2
		\
		1
		/
		9
	*/

	struct Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	root->right->left->right = newNode(1);
	root->right->left->right->left = newNode(9);

	cout << findMaxBends(root) - 1;

	return 0;
}
