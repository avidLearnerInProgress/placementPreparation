#include<bits/stdc++.h>
 using namespace std;

struct node
{
    int data;
    struct node* next;
};
 

void printMiddle(struct node *head)
{
	struct node *mid=head;
	int count=0;
	while(head!=NULL)
	{
		if(count & 1)
			mid=mid->next;
	count++;			
	head=head->next;
	}
	if(mid!=NULL)
		cout<<mid->data<<endl;
	return;
}
 
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}
 

void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
 

int main()
{

    struct node* head = NULL;
    int i;
 
    for (i=5; i>0; i--)
        push(&head, i);
    
       
    
        printList(head);
  	printMiddle(head);
    return 0;
}
