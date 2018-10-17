/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int diameterUtil(Node* root,int* height)
{
    if(root==NULL)
    {
        *height = 0;
        return 0;
    }
    
    int left=0,right=0;
    int left_dia  = diameterUtil(root->left,&left);
    int right_dia = diameterUtil(root->right,&right);
    
    *height = 1+max(left,right);
    
    return max(1+left+right,max(left_dia,right_dia));
    
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node)
{
    int height = 0;
    return diameterUtil(node,&height);
}