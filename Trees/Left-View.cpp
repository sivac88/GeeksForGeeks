// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

typedef struct node Node;

void leftViewUtil(Node* root,int* max_lvl,int cur)
{
    if(root==NULL) return;

    if(cur>(*max_lvl))
    {
        cout<<(root->data)<<" ";
        *max_lvl = cur;
    }

    leftViewUtil(root->left,max_lvl,cur+1);
    leftViewUtil(root->right,max_lvl,cur+1);
}

void leftView(Node* root)
{
    int max_level = 0;
    leftViewUtil(root,&max_level,1);
}


int main()
{
	struct node *root = newNode(12);
	root->left = newNode(10);
	root->right = newNode(30);
	root->right->left = newNode(25);
	root->right->right = newNode(40);

	leftView(root);

	return 0;
}
