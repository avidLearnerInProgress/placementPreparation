#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void deleteAlt(struct node *head)
{
    if (head == NULL)
        return;
    struct node *prev = head;
    struct node *node = head->next;
 
    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}



void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 

int main()
{

    struct node* head = NULL;
 

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\nList before calling deleteAlt() \n");
    printList(head);
 
    deleteAlt(head);
 
    printf("\nList after calling deleteAlt() \n");
    printList(head);
 
    return 0;
}
