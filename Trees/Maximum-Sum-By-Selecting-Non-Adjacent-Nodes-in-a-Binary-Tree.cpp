// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
typedef struct node Node;

pair<int,int> getMaxSumUtil(Node* root)
{
    if(root==NULL)
        return make_pair(0,0);

    pair<int,int> left = getMaxSumUtil(root->left);
    pair<int,int> right = getMaxSumUtil(root->right);

    int sum_inclusive = root->data + left.second + right.second;
    int sum_exclusive = max(left.first,left.second)+max(right.first,right.second);

    return make_pair(sum_inclusive,sum_exclusive);

}

int getMaxSum(Node* root)
{
    if(root==NULL) return 0;
    pair<int,int> p = getMaxSumUtil(root);
    return max(p.first,p.second);
}

int getMaxSumRec(Node* root)
{
    if(root==NULL) return 0;

    int sum_inclusive = root->data;
    if(root->left)
        sum_inclusive+=getMaxSumRec(root->left->left)+getMaxSumRec(root->left->right);
    if(root->right)
        sum_inclusive+=getMaxSumRec(root->right->left)+getMaxSumRec(root->right->right);

    int sum_exclusive = getMaxSumRec(root->left)+getMaxSumRec(root->right);

    return max(sum_inclusive,sum_exclusive);
}

int getMaxSumTopDown(Node* root,unordered_map<Node*,int>& m)
{
    if(root==NULL) return 0;
    if(m.find(root)!=m.end())
        return m[root];
    int sum_inclusive = root->data;
    if(root->left)
        sum_inclusive += getMaxSumTopDown(root->left->left,m)+getMaxSumTopDown(root->left->right,m);
    if(root->right)
        sum_inclusive += getMaxSumTopDown(root->right->left,m)+getMaxSumTopDown(root->right->right,m);

    int sum_exclusive = getMaxSumTopDown(root->left,m) + getMaxSumTopDown(root->right,m);

    m[root]=max(sum_inclusive,sum_exclusive);
    return m[root];
}

int getMaxSumDP(Node* root)
{
    unordered_map<Node*,int> m;
    return getMaxSumTopDown(root,m);
}

// Driver code to test above methods
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSumDP(root) << endl;
	return 0;
}
