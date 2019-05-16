// Recursive program to check if a given linked list is palindrome
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Link list node */
struct node
{
	char data;
	struct node* next;
};

typedef struct node Node;

bool isPalindromeUtil(Node** left,Node* head)
{
    if(head==NULL) return true;

    bool isRightPalindrome = isPalindromeUtil(left,head->next);
    if(!isRightPalindrome)
        return false;

    bool areSame = ((*left)->data == head->data);
    (*left) = (*left)->next;
    return areSame;
}

Node* reverseLL(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* rev_right = reverseLL(head->next);
    head->next->next = head;
    return rev_right;
}

bool compare(Node* head1,Node* head2)
{
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data != head2->data)
            return false;
        head1=head1->next;
        head2 = head2->next;
    }

    if(head1==NULL && head2!=NULL)
        return false;

    if(head1!=NULL && head2==NULL)
        return false;

    return true;
}

bool isPalindromeUtilNaive(Node* head)
{
    if(head==NULL || head->next==NULL)
    return true;

    Node* slow=head,*fast=head,*prev_slow=NULL;
    while(fast && fast->next)
    {
        prev_slow = slow;
        slow = slow->next;
        fast=fast->next->next;
    }

    if(fast!=NULL){
        prev_slow->next = NULL;
        slow=slow->next;
    }

    Node* rev = reverseLL(slow);
    return compare(head,rev);
}

bool isPalindrome(Node* head)
{
    //return isPalindromeUtil(&head,head);
    return isPalindromeUtilNaive(head);
}
/* Push a node to linked list. Note that this function
changes the head */
void push(struct node** head_ref, char new_data)
{
	/* allocate node */
	struct node* new_node =
			(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to pochar to the new node */
	(*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%c->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	char str[] = "abacaba";
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	push(&head, str[i]);
	printList(head);
	isPalindrome(head)? printf("Is Palindrome\n\n"):
						printf("Not Palindrome\n\n");
	}

	return 0;
}
