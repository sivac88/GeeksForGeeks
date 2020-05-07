// C++ program to find minimum time required
// to burn the binary tree completely

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
	int data;
	Node* left;
	Node* right;

	Node()
	{
		left = NULL;
		right = NULL;
	}
};

// Utility function to create a new Node
Node* newNode(int val)
{
	Node* temp = new Node;

	temp->data = val;

	return temp;
}

int ans = 0;
bool isFound = false;

int findEle(Node* root,int ele,int timeToburn)
{
    if(root==NULL) return 0;
    if(root->data == ele)
    {
        isFound = true;
        return 1;
    }
    if(!isFound)
    {
        int l = findEle(root->left,ele,timeToburn);
        if(l>0)
        {
            ans = max(ans,1+l);
            findEle(root->right,ele,1+l);
            return 1+l;
        }
        int r = findEle(root->right,ele,timeToburn);
        if(r>0)
        {
            ans = max(ans,1+r);
            findEle(root->left,ele,1+r);
            return 1+r;
        }
    }
    else
    {
        ans = max(ans,1+timeToburn);
        findEle(root->left,ele,1+timeToburn);
        findEle(root->right,ele,1+timeToburn);
    }
    return 0;
}


// Driver function to calculate minimum
// time required
int minTime(Node* root, int target)
{
	findEle(root,target,0);
	return ans;
}

map<int,list<int> > m;

int insertInMap(Node* root,int ele,int timeToBurn)
{
    if(root==NULL) return 0;
    if(root->data == ele)
    {
        isFound = true;
        m[1+timeToBurn].push_back(root->data);
        insertInMap(root->left,ele,1+timeToBurn);
        insertInMap(root->right,ele,1+timeToBurn);
        return 1;
    }
    if(!isFound)
    {
        int l = insertInMap(root->left,ele,timeToBurn);
        if(l>0)
        {
            m[1+l].push_back(root->data);
            insertInMap(root->right,ele,1+l);
            return 1+l;
        }
        int r = insertInMap(root->right,ele,timeToBurn);
        if(r>0)
        {
            m[1+r].push_back(root->data);
            insertInMap(root->left,ele,1+r);
            return 1+r;
        }
    }
    else
    {
        m[1+timeToBurn].push_back(root->data);
        insertInMap(root->left,ele,1+timeToBurn);
        insertInMap(root->right,ele,1+timeToBurn);
    }
    return 0;
}

void printNodesInBurningOrder(Node* root,int ele)
{
    insertInMap(root,ele,0);
    for (auto it = m.begin(); it != m.end(); it++)
    {
       cout << it->first << ":";
       for (auto lit = it->second.begin(); lit  != it->second.end(); lit++)
          cout << " " << (*lit);
       cout << "\n";
    }
}


// Driver Code
int main()
{
  //TASK-1 -- https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/?ref=leftbar-rightbar

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(8);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(10);
	root->left->right->left->left = newNode(11);

	// target node is 8
	int target = 11;
	cout << minTime(root, target);

	return 0;



//TASK-2 https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/?ref=rp

/*

    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(13);

    root->right->left = newNode(14);
    root->right->right = newNode(15);

    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);
    int targetNode = 14;

    printNodesInBurningOrder(root,targetNode);
    */

	return 0;
}
