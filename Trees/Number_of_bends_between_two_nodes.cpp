// C++ Program to count number of turns
// in a Binary Tree.
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node {
	struct Node* left, *right;
	int key;
};

// Utility function to create a new
// tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

Node* findLCA(Node* root,int v1,int v2)
{
    if(root==NULL) return NULL;
    if(root->key == v1 || root->key == v2)
        return root;

    Node* left = findLCA(root->left,v1,v2);
    Node* right = findLCA(root->right,v1,v2);

    if(left && right)
        return root;

    if(left)
        return left;

    return right;
}

void countTurns(Node* root,int v1,int* v1_turns,int v2,int* v2_turns,
                bool* isv1found,bool* isv2found,bool isLeft,int cur_turns)
{
    if(root==NULL) return;
    if(root->key == v1)
    {
        *v1_turns = cur_turns;
        *isv1found = true;
    }
    if(root->key == v2)
    {
        *v2_turns = cur_turns;
        *isv2found = true;
    }
    if(isLeft){
        countTurns(root->left,v1,v1_turns,v2,v2_turns,isv1found,isv2found,true,cur_turns);
        countTurns(root->right,v1,v1_turns,v2,v2_turns,isv1found,isv2found,false,cur_turns+1);
    }
    else
    {
        countTurns(root->left,v1,v1_turns,v2,v2_turns,isv1found,isv2found,true,cur_turns+1);
        countTurns(root->right,v1,v1_turns,v2,v2_turns,isv1found,isv2found,false,cur_turns);
    }

}

int NumberOFTurn(Node* root,int v1,int v2)
{
    Node* lca_node = findLCA(root,v1,v2);
    int v1_turns = 0,v2_turns=0;
    bool v1_found = false,v2_found=false;
    countTurns(root->left,v1,&v1_turns,v2,&v2_turns,&v1_found,&v2_found,true,0);
    countTurns(root->right,v1,&v1_turns,v2,&v2_turns,&v1_found,&v2_found,false,0);
    if(lca_node->key != v1 && lca_node->key != v2)
        return 1+v1_turns+v2_turns;
    else if(lca_node->key == v1)
            return v2_turns;
    return v1_turns;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in the above
	// example
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->right->left->left = newNode(9);
	root->right->left->right = newNode(10);

	int turn = 0;
	if ((turn = NumberOFTurn(root, 5, 10)))
		cout << turn << endl;
	else
		cout << "Not Possible" << endl;

	return 0;
}
