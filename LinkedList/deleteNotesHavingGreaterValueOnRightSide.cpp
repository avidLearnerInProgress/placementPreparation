#include <stdio.h>
#include <stdlib.h>

/* structure of a linked list node */
struct node
{
     int data;
     struct node *next;
};


/* Deletes nodes which have a node with greater value node
  on left side */
struct node* delLesserNodes_recursive(struct node **head)
{
    /* Base case (end of list) */
    if((*head)==NULL||(*head)->next==NULL) return (*head);

    struct node *temp=(*head),*current;

    current=delLesserNodes_recursive(&((*head)->next));

    /* Delete head if data at head is less than the current node
       and point it current node*/
    if((*head)->data<current->data)
    {
        (*head)=current;
        free(temp);
    }
  /* return modified head */
  return (*head);
}

/* Utility function to insert a node at the begining */
void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}

/* Utility function to print a linked list */
void printList(struct node *head)
{
     while(head!=NULL)
     {
        printf("%d ",head->data);
        head=head->next;
     }
     printf("\n");
}

/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;

    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

    printf("Given Linked List: ");
    printList(head);

    delLesserNodes_recursive(&head);

    printf("\nModified Linked List: ");
    printList(head);

    getchar();
    return 0;
}

