// C++ program to clone a linked list with next
// and arbit pointers in O(n) time
#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next,*random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

void printNext(Node* head)
{
    cout<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

// This function clones a given linked list
// in O(1) space
Node* clone(Node *start)
{
    Node* store = start;

    while(start)
    {
        Node* temp = start->next;
        Node* newNode = new Node(start->data);
        start->next=newNode;
        newNode->next=temp;
        start=temp;
    }

    start = store;

    while(start)
    {
        start->next->random = start->random ? start->random->next : start->random;
        start = start->next->next;
    }

    Node* clonedHead = store->next;
    Node* store_cloneHead = clonedHead;
    start = store;

    while(start)
    {
        start->next=start->next->next;
        clonedHead->next = clonedHead->next ? clonedHead->next->next : NULL;
        start = start->next;
        clonedHead = clonedHead->next;
    }

    return store_cloneHead;
}

// Driver code
int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);

    return 0;
}
