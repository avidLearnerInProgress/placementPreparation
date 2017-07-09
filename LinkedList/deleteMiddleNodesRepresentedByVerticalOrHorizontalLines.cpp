#include <bits/stdc++.h>
#include <stdlib.h>

using  namespace std;
// Node has 3 fields including x, y coordinates and a pointer
// to next node
struct node
{
    int x, y;
    struct node *next;
};

/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int x,int y)
{
    struct node* new_node =
           (struct node*) malloc(sizeof(struct node));
    new_node->x  = x;
    new_node->y  = y;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("(%d,%d)-> ", temp->x,temp->y);
        temp = temp->next;
    }
    printf("\n");

}

// Utility function to remove Next from linked list
// and link nodes after it to head
void deleteNode(struct node *head, struct node *Next)
{
    head->next = Next->next;
    Next->next = NULL;
    free(Next);
}

// This function deletes middle nodes in a sequence of
// horizontal and vertical line segments represented by
// linked list.
struct node* deleteMiddle(struct node *head)
{
    if(!head) return NULL;
    node* curr = head;
    while(curr && curr->next && curr->next->next) {
        if( (curr->x == curr->next->x && curr->next->x == curr->next->next->x) || // if any vertical line
            (curr->y == curr->next->y && curr->next->y == curr->next->next->y)) // if any horizontal line
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

// Driver program to tsst above functions
int main()
{
    struct node *head = NULL;

    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    printf("Given Linked List: \n");
    printList(head);

    if (deleteMiddle(head) != NULL);
    {
        printf("Modified Linked List: \n");
        printList(head);
    }
    return 0;
}

