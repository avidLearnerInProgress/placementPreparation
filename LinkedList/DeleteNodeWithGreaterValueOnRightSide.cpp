#include<bits/stdc++.h>


struct node
{
     int data;
     struct node *next;
};
 
void reverseList(struct node **headref)
{
     struct node *current = *headref;
     struct node *prev = NULL;
     struct node *next;
     while (current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     *headref = prev;
}


void __delLesserNodes(struct node *head){
	
	struct node *curr=head;
	struct node *maxnode=head;
	struct node *temp;
	while(curr!=NULL && curr->next!=NULL){
	
	if(curr->next->data < maxnode->data){
		temp=curr->next;
		curr->next=temp->next;
		free(temp);
	}
	else{
		curr=curr->next;
		maxnode=curr;
	}
}
	
}

void delLesserNodes(struct node **head_ref){
	
	//struct node *temp=*head_ref;
	reverseList(head_ref);
	
	__delLesserNodes(*head_ref);
	
	reverseList(head_ref);
	
}



void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}



void printList(struct node *head)
{
     while (head != NULL)
     {
        printf("%d ", head->data);
        head=head->next;
     }
     printf("\n");
}
 
 
 
 

int main()
{
    struct node *head = NULL; 
 
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List \n");
    printList(head);
 
    delLesserNodes(&head);
 
    printf("Modified Linked List \n");
    printList(head);
 
     return 0;
}


