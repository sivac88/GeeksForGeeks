#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* newNode(int data)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrder(Node* root)
{
    if(root)
    {
        cout<<(root->data)<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* delLeafValueK(Node* root,int k)
{
    if(root==NULL) return NULL;
    root->left=delLeafValueK(root->left,k);
    root->right=delLeafValueK(root->right,k);
    if(root->left==NULL && root->right==NULL && root->data == k)
    {
        free(root);
        return NULL;
    }
    return root;
}

int main()
{
    Node* root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(1);
    root->right->left = newNode(5);

    cout<<"Nodes in postorder before deletion:";
    preOrder(root);
    cout<<endl;
    cout<<"Nodes in post order after required deletion"<<endl;
    int k = 5;
    root=delLeafValueK(root, k);
    preOrder(root);
    cout<<endl;
}
