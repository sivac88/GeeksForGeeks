// A C++ program to demonstrate serialization and deserialiation of
// Binary Tree
#include <stdio.h>
#define MARKER -1

/* A binary tree Node has key, pointer to left and right children */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Helper function that allocates a new Node with the
given key and NULL left and right pointers. */
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

int countNodesWithNULL(Node* root)
{
    if(root==NULL) return 1;
    return 1+countNodesWithNULL(root->left)+countNodesWithNULL(root->right);
}

void serialize(Node* root,int* arr,int* idx)
{
    if(root==NULL)
    {
        arr[(*idx)++] = -1;
        return;
    }

    arr[(*idx)++] = root->key;
    serialize(root->left,arr,idx);
    serialize(root->right,arr,idx);
}


Node* deSerialize(int* arr,int* idx)
{
    if(arr[(*idx)]==-1)
    {
        (*idx)++;
        return NULL;
    }

    Node* new_Node = newNode(arr[(*idx)++]);
    new_Node->left = deSerialize(arr,idx);
    new_Node->right = deSerialize(arr,idx);
    return new_Node;
}


// A simple inorder traversal used for testing the constructed tree
void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void printArray(int* a,int n)
{
    printf("Contents of serialized array are ... \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

/* Driver program to test above functions*/
int main()
{
	// Let us construct a tree shown in the above figure
	struct Node *root	 = newNode(20);
	root->left			 = newNode(8);
	root->right			 = newNode(22);
	root->left->left		 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

    int n = countNodesWithNULL(root);
    int arr[n];
    int idx=0;
	serialize(root,arr,&idx);

	printArray(arr,idx);

	idx = 0;
	Node* root1=deSerialize(arr,&idx);

	printf("Inorder Traversal of the tree constructed from file:\n");
	inorder(root1);

	return 0;
}
