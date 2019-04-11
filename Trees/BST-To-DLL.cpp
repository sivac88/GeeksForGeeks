// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
and left and right pointers */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

typedef node Node;

void bintree2listUtil(Node* root,Node** head)
{
    if(root==NULL) return;
    bintree2listUtil(root->right,head);
    if((*head)==NULL)
        (*head)=root;
    else
    {
        (*head)->left=root;
        root->right=(*head);
        (*head)=root;
    }
    bintree2listUtil(root->left,head);
}

Node* bintree2list(Node* root)
{
   Node* head=NULL;
   bintree2listUtil(root,&head);
   return head;
}


/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->right;
	}
}

/* Driver code*/
int main()
{
	// Let us create the tree shown in above diagram
	node *root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node *head = bintree2list(root);

	// Print the converted list
	printList(head);

	return 0;
}
