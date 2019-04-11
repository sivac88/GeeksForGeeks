// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	int data; //data of the node
	int hd; //horizontal distance of the node
	Node *left, *right; //left and right references

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void bottomViewUtil(Node* root,map<int,pair<int,int> >& m,int dist,int depth)
{
    if(root==NULL)
        return;

    if(m.find(dist)==m.end())
        m[dist]=make_pair(root->data,depth);
    else
    {
        pair<int,int> p = m[dist];
        if(p.second < depth)
        {
            m.erase(dist);
            m[dist] = make_pair(root->data,depth);
        }
    }

    bottomViewUtil(root->left,m,dist-1,depth+1);
    bottomViewUtil(root->right,m,dist+1,depth+1);
}

void bottomView(Node* root)
{
    map<int,pair<int,int> > m;
    bottomViewUtil(root,m,0,0);
    for(pair<int,pair<int,int> > p : m)
    {
        cout<<p.second.first<<" ";
    }
}

// Driver Code
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	bottomView(root);
	return 0;
}
