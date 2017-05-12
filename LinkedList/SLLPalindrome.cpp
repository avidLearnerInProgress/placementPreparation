
#include<bits/stdc++.h> 

struct node
{
    char data;
    struct node* next;
};
 
void reverse(struct node**);
bool compareLists(struct node*, struct node *);

bool isPalindrome(struct node *head)
{
	struct node *slowPtr=head;
	struct node *prevSlowPtr=head;
	struct node *fastPtr=head;
	struct node *midNode=NULL;
	struct node *secondHalf;
	bool res=true;
	
	if(head!=NULL && head->next!=NULL){
		while(fastPtr!=NULL && fastPtr->next!=NULL){
			fastPtr=fastPtr->next->next;
			prevSlowPtr=slowPtr;
			slowPtr=slowPtr->next;
			
		}
		
		if(fastPtr!=NULL){
			midNode=slowPtr;
			slowPtr=slowPtr->next;
		}
		
		secondHalf=slowPtr;
	prevSlowPtr->next=NULL;
		reverse(&secondHalf);
		res=compareLists(head,secondHalf);
		reverse(&secondHalf);
		
		if(midNode!=NULL){
			prevSlowPtr->next=midNode;
			midNode->next=secondHalf;
		}
		else
			prevSlowPtr->next=secondHalf;
	}
		return res;
	
}

void push(struct node** head_ref, char new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
void reverse(struct node **head_ref) {
	
	struct node *curr=*head_ref;
	struct node *prev=NULL;
	struct node *next;
	
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head_ref=prev;
}
 
bool compareLists(struct node *head1, struct node *head2) {
	
	struct node *temp1=head1;struct node *temp2=head2;
	while(temp1 && temp2){
		if(temp1->data == temp2->data){
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else return 0;
	}
	  if (temp1 == NULL && temp2 == NULL)
        return 1;
      
       return 0;
}


int main()
{

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
