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


int length(Node* node)
{
    if(node==NULL) return 0;
    
    return 1+max(length(node->left),length(node->right));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node)
{
   if(node==NULL) return 0;
   
   int left_max_len=length(node->left);
   int right_max_len=length(node->right);
   
   return max(1+left_max_len+right_max_len,
              max(diameter(node->left),
              diameter(node->right)));
   
}