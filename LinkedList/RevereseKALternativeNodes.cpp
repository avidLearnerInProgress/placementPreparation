#include<stdio.h>
#include<stdlib.h>
 
 
 /*
 //Output:
Given linked list
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Modified Linked list
3 2 1 4 5 6 9 8 7 10 11 12 15 14 13 16 17 18 20 19
 */
 
 
 

struct node
{
    int data;
    struct node* next;
};

struct node *kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;   
 
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
   
    /* 2) Now head points to the kth node.  So change next 
       of head to (k+1)th node*/
    if(head != NULL)
      head->next = current;   
 
    /* 3) We do not want to reverse next k nodes. So move the current 
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
 
    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k); 
 
    /* 5) prev is new head of the input list */
    return prev;
}


/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    // create a list 1->2->3->4->5...... ->20
    for(int i = 20; i > 0; i--)
      push(&head, i);
 
     printf("\n Given linked list \n");
     printList(head);
     head = kAltReverse(head, 3);
 
     printf("\n Modified Linked list \n");
     printList(head);
 
     getchar();
     return(0);
}



