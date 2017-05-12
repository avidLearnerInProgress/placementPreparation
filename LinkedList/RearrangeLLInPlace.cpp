

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
 

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 

void reverselist(Node **head)
{

    Node *prev = NULL, *curr = *head, *next;
 
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}
 

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        if(head->next) cout << "-> ";
        head = head->next;
    }
    cout << endl;
}
 

void rearrange(Node **head)
{
	Node *slow_ptr=*head;
	Node *fast_ptr=*head;
	
	while(fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		
	}
	Node *head1=*head;
	Node *head2=slow_ptr->next;
	slow_ptr->next=NULL;
	
	reverselist(&head2);
	*head=newNode(0);
	
	Node *curr=*head;
	
	while(head1 || head2){
		if(head1){
			curr->next=head1;
			head1=head1->next;
			curr=curr->next;
			
		}
		if(head2){
			curr->next=head2;
			head2=head2->next;
			curr=curr->next;
		}
		
	}
	*head=(*head)->next;
	
    
}
 

int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    printlist(head);    // Print original list
    rearrange(&head);       // Modify the list
    printlist(head);    // Print modified list
    return 0;
}
