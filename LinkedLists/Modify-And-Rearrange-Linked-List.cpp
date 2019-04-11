// C++ implementation to modify and
// rearrange list
#include <bits/stdc++.h>
using namespace std;

// structure of a node
struct Node {
	int data;
	Node* next;
};

// function to get a new node
Node* getNode(int data)
{
	// allocate space
	Node* newNode = (Node*)malloc(sizeof(Node));

	// put in the data
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

Node* rearrange(Node* head)
{
    Node* nonZero_start=NULL,*nonZero_end,*zero_start=NULL,*zero_end;
    while(head!=NULL)
    {
        if(head->data != 0)
        {
            if(nonZero_start==NULL)
            {
                nonZero_start = head;
                nonZero_end = nonZero_start;
            }
            else
            {
                nonZero_end->next = head;
                nonZero_end = nonZero_end->next;
            }
        }
        else
        {
            if(zero_start==NULL)
            {
                zero_start = head;
                zero_end = zero_start;
            }
            else
            {
                zero_end->next = head;
                zero_end = zero_end->next;
            }
        }

        head = head->next;
    }

    nonZero_end->next = zero_start;
    zero_end->next = NULL;

    return nonZero_start;
}

Node* modifyAndRearrangeList(Node* head)
{
    if(!head || !(head->next)) return head;
    Node* store= head;
    while(head && head->next)
    {
        if(head->data==0 || (head->data)!=(head->next->data))
            head = head->next;
        else
        {
            head->data = 2*(head->data);
            head->next->data = 0;
            head = head->next->next;
        }
    }

    return rearrange(store);
}

// function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	Node* head = getNode(2);
	head->next = getNode(2);
	head->next->next = getNode(0);
	head->next->next->next = getNode(4);
	head->next->next->next->next = getNode(0);
	head->next->next->next->next->next = getNode(8);

	cout << "Original List: ";
	printList(head);

	head = modifyAndRearrangeList(head);

	cout << "\nModified List: ";
	printList(head);

	return 0;
}
