// C++ program to Append odd position nodes
// in reverse at the end of even
// positioned nodes in a Linked List
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node {
	int data;
	struct Node* next;
};

// A utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void rearrangeEvenOdd(Node* head)
{
    if(head==NULL || head->next==NULL || head->next->next==NULL) return;

    Node* odd=head,*even=NULL;

    while(odd->next)
    {
        Node* store = odd->next->next;
        odd->next->next = even;
        even = odd->next;
        odd->next = store;
        if(odd->next)
        odd = odd->next;
    }

    odd->next = even;
}

// A utility function to print a linked list
void printlist(Node* node)
{
	while (node != NULL) {
		cout << node->data << " -> ";
		node = node->next;
	}
	cout << "NULL" << endl;
}

// Driver code
int main(void)
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

	rearrangeEvenOdd(head);

	printlist(head);

	return 0;
}
