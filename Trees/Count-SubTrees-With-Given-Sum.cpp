// C++ implementation to count subtress that
// sum up to a given value x
#include <bits/stdc++.h>

using namespace std;

// structure of a node of binary tree
struct Node {
    int data;
    Node *left, *right;
};

// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* newNode = (Node*)malloc(sizeof(Node));

    // put in the data
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countUtil(Node* root,int* sum,int x)
{
    if(root==NULL)
    {
        *sum=0;
        return 0;
    }
    int left=0,right=0,ans=0;
    ans+=countUtil(root->left,&left,x);
    ans+=countUtil(root->right,&right,x);

    (*sum) = left+right+root->data;

    if((*sum)==x)
        ans+=1;

    return ans;
}

int countSubtreesWithSumXUtil(Node* root,int x)
{
    int sum=0;
    return countUtil(root,&sum,x);
}

int main()
{
    /* binary tree creation
                5
            / \
        -10  3
        / \ / \
        9 8 -4 7
    */
    Node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int x = 7;

    cout << "Count = "
        << countSubtreesWithSumXUtil(root, x);

    return 0;
}
