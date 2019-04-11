#include <iostream>
using namespace std;

// A binary Tree node
struct node
{
	int data;
	struct node *left, *right;
};

typedef struct node Node;

node *newnode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printAllDownNodes(Node* root,int k,int cur)
{
    if(root==NULL || cur>k) return;
    if(cur==k)
    {
        cout<<(root->data)<<" ";
        return;
    }

    printAllDownNodes(root->left,k,cur+1);
    printAllDownNodes(root->right,k,cur+1);
}

int printkdistanceNode(Node* root,Node* target,int k)
{
    if(root==NULL) return -1;

    if(root == target)
    {
        printAllDownNodes(target,k,0);
        return 0;
    }

    int left = printkdistanceNode(root->left,target,k);

    if(left!=-1)
    {
        if(left+1==k)
        {
            cout<<(root->data)<<" ";
            return 1+left;
        }

        printAllDownNodes(root->right,k-left-2,0);
        return 1+left;
    }

    int right = printkdistanceNode(root->right,target,k);

    if(right!=-1)
    {
        if(right+1==k)
        {
            cout<<(root->data)<<" ";
            return 1+right;
        }

        printAllDownNodes(root->left,k-right-2,0);
        return 1+right;
    }

    return -1;

}

int main()
{
	/* Let us construct the tree shown in above diagram */
	node * root = newnode(20);
	root->left = newnode(8);
	root->right = newnode(22);
	root->left->left = newnode(4);
	root->left->right = newnode(12);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(14);
	node * target = root->left->right;
	printkdistanceNode(root, target, 2);
	return 0;
}
