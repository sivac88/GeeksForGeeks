// A recursive program to add two linked lists

#include <stdio.h>
#include <stdlib.h>

// A linked List Node
struct Node
{
	int data;
	struct Node* next;
};

typedef struct Node node;

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("n");
}

void swap(Node** head1,Node** head2)
{
    Node* temp = (*head1);
    (*head1) = (*head2);
    (*head2) = temp;
}

Node* addRemaining(Node* head,Node* stop,int* carry)
{
    if(head!=stop)
    {
        Node* result = (Node*)malloc(sizeof(Node));
        result->next = addRemaining(head->next,stop,carry);
        int sum = (head->data)+(*carry);
        result->data = sum%10;
        (*carry) = sum/10;
        return result;
    }
    return NULL;
}

Node* addSameSize(Node* head1,Node* head2,int* carry)
{
    if(head1==NULL) return NULL;

    Node* result = (Node*)malloc(sizeof(Node));

    result->next = addSameSize(head1->next,head2->next,carry);

    int sum = (head1->data)+(head2->data)+(*carry);

    result->data = sum%10;

    (*carry) = sum/10;

    return result;
}

int countNodes(Node* head)
{
    if(head==NULL) return 0;
    return 1+countNodes(head->next);
}


void addList(Node* head1,Node* head2,Node** result)
{
    if(head1==NULL)
    {
        *result = head2;
        return;
    }

    if(head2==NULL)
    {
        *result = head1;
        return;
    }

    int n1 = countNodes(head1);
    int n2 = countNodes(head2);

    Node* newHead,*store;
    int carry = 0;

    if(n1==n2)
        newHead = addSameSize(head1,head2,&carry);
    else
    {
        if(n1<n2)
            swap(&head1,&head2);
        int diff = abs(n1-n2);
        store = head1;
        for(int i=0;i<diff;i++)
            head1 = head1->next;
        Node* newHead1 = addSameSize(head1,head2,&carry);
        newHead=addRemaining(store,head1,&carry);
        newHead->next = newHead1;
    }

    if(carry)
        push(&newHead,carry);

    (*result) = newHead;
}

// Driver program to test above functions
int main()
{
	Node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = {9, 9, 9};
	int arr2[] = {1, 8};

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 9->9->9
	int i;
	for (i = size1-1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2-1; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);

	printList(result);

	return 0;
}
