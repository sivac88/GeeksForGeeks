//https://stackoverflow.com/questions/17119116/how-many-ways-can-you-insert-a-series-of-values-into-a-bst-to-form-a-specific-tr#
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int combination(int n,int r)
{
    int n_fact=1;
    for(int i=1;i<=n;i++)
        n_fact*=i;
    int r_fact=1;
    for(int i=1;i<=r;i++)
        r_fact*=i;
    int nminusr_fact=1;
    for(int i=1;i<=(n-r);i++)
        nminusr_fact*=i;

    return n_fact/(nminusr_fact*r_fact);
}

int countUtil(Node* root,int* count)
{
    if(root==NULL)
    {
        *count = 0;
        return 1;
    }

    int left=0,right=0;
    int leftordering = countUtil(root->left,&left);
    int rightordering = countUtil(root->right,&right);

    *count = (left+right+1);

    return combination(left+right,left)*leftordering*rightordering;
}

int countAllPossibleOrderings(Node* root)
{
    if(root==NULL) return 0;
    int numberofnodes = 0;
    return countUtil(root,&numberofnodes);
}

int main()
{
    Node* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->left = createNode(0);
    root->left->right = createNode(2);

    cout<<countAllPossibleOrderings(root);
}
