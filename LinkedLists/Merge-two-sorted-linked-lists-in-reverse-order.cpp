/* Given two sorted non-empty linked lists. Merge them in
such a way that the result list will be in reverse
order. Reversing of linked list is not allowed. Also,
extra space should be O(1) */
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
	int key;
	struct Node* next;
};

Node* SortedMerge(Node* head1,Node* head2)
{
    Node* result=NULL,*next;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->key <= head2->key)
        {
            next = head1->next;
            head1->next = result;
            result = head1;
            head1 = next;
        }
        else
        {
            next = head2->next;
            head2->next = result;
            result = head2;
            head2 = next;
        }
    }

    while(head1!=NULL)
    {
        next = head1->next;
        head1->next = result;
        result = head1;
        head1 = next;
    }

    while(head2!=NULL)
    {
        next = head2->next;
        head2->next = result;
        result = head2;
        head2 = next;
    }

    return result;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *Node)
{
	while (Node!=NULL)
	{
		cout << Node->key << " ";
		Node = Node->next;
	}
}

Node* SortedMergeIncresing(Node* head1,Node* head2)
{
    Node* front=NULL,*back=NULL;
    printList(head2);
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->key <= head2->key)
        {
            if(front==NULL)
            {
                front = head1;
                back  = head1;
            }
            else
            {
                back->next = head1;
                back = head1;
            }
            head1=head1->next;
        }
        else
        {
            if(front==NULL)
            {
                front = head2;
                back  = head2;
            }
            else
            {
                back->next = head2;
                back = head2;
            }
            head2=head2->next;
        }
    }

    while(head1!=NULL)
    {
        if(front==NULL)
        {
            front = head1;
            back  = head1;
        }
        else
        {
            back->next = head1;
            back = head1;
        }
        head1=head1->next;
    }

    while(head2!=NULL)
    {
        if(front==NULL)
        {
            front = head2;
            back  = head2;
        }
        else
        {
            back->next = head2;
            back = head2;
        }
        head2=head2->next;
    }

    return front;
}

/* Utility function to create a new node with
given key */
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* res = NULL,*res1;

	/* Let us create two sorted linked lists to test
	the above functions. Created lists shall be
		a: 5->10->15
		b: 2->3->20 */
	Node *a = newNode(5);
	a->next = newNode(10);
	a->next->next = newNode(15);

	Node *b = newNode(2);
	b->next = newNode(3);
	b->next->next = newNode(20);

	cout << "List A before merge: \n";
	printList(a);

	cout << "\nList B before merge: \n";
	printList(b);

	/* merge 2 increasing order LLs in descresing order */
	res = SortedMerge(a, b);

	cout << "\nMerged Linked List in reverse order: \n";
	printList(res);

//	/* merge 2 increasing order LLs in increasing order */
//	res1 = SortedMergeIncresing(a, b);
//
//	cout << "\nMerged Linked List in increasing order: \n";
//	printList(res1);

	return 0;
}
