// C++ program for printing vertical order of a given binary tree
#include <bits/stdc++.h>
using namespace std;

// Structure for a binary tree node
struct Node
{
	int key;
	Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

void printVerticalOrderUtil(Node* root,int x,map<int,list<int> >& m)
{
    if(root==NULL) return;
    m[x].push_back(root->key);
    printVerticalOrderUtil(root->left,x-1,m);
    printVerticalOrderUtil(root->right,x+1,m);
}

/*

The above will not work the example given in this main
it prints left subtree value and then right but if left is below right then we should not print it first
so we have to maintain height as well along with horizantal distance. ( similar to top view of a tree)

// C++ program for printing vertical order
// of a given binary tree usin BFS.
#include<bits/stdc++.h>

using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

bool cmp(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void printVerticalUtil(Node* root,int lvl,int height,map<int,vector<pair<int,int> > >& m)
{
    if(root==NULL) return;
    m[lvl].push_back(make_pair(root->key,height));
    printVerticalUtil(root->left,lvl-1,height+1,m);
    printVerticalUtil(root->right,lvl+1,height+1,m);
}

void printVerticalOrder(Node* root)
{
    map<int,vector<pair<int,int> > > m;
    printVerticalUtil(root,0,0,m);
    for(pair<int,vector<pair<int,int> > > p : m)
    {
        sort(p.second.begin(),p.second.end(),cmp);
        cout<<"Level "<<p.first<<" :";
        for(int i=0;i<p.second.size();i++)
            cout<<p.second[i].first<<" ";
        cout<<endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}

*/

void printVerticalOrderUtilBFS(Node* root,map<int,list<int> >& m)
{
    queue<pair<Node*,int> > q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        Node* cur = p.first;
        int dist = p.second;
        m[dist].push_back(cur->key);
        q.pop();
        if(cur->left)
            q.push({cur->left,dist-1});
        if(cur->right)
            q.push({cur->right,dist+1});
    }
}

void printVerticalOrder(Node* root)
{
    int x_dist = 0;
    map<int,list<int> > m;
    //printVerticalOrderUtil(root,x_dist,m);
    printVerticalOrderUtilBFS(root,m);
    for(pair<int,list<int> > p : m)
    {
        list<int> l = p.second;
        cout<<"Contents of line "<<(p.first)<< " are ...";
        for(int val : l)
            cout<<val<<" ";
        cout<<endl;
    }
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is \n";
	printVerticalOrder(root);
	return 0;
}
