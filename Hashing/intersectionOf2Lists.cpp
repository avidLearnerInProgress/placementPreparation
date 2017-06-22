/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/

node *insert(node *head,int data){
	node *temp=new node();
	temp->data=data;
	if(head==NULL||head->data>data)
	{
		temp->next=head;
		head=temp;
		return head;
	}
	node *curr=head;
	while(curr->next!=NULL&&curr->next->data<data)
	    curr=curr->next;
    temp->next=curr->next;
    curr->next=temp;
    return head;		
}

/*node *createNode(int x){
    node *temp=new node();
    node->data=x;
    node->next=NULL;
    return node;
}*/
/*
struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    
   // map<int,int> mp;
   int hash[1001]={0};
    node *head=NULL;
    while(head1){
        hash[head1->data]++;
        head1=head1->next;
    }
    
    while(head2){
        if(hash[head2->data]){
            hash[head2->data]--;
            head=insert(head,head2->data);
        }
        head2=head2->next;
    }
    return head;
}

*/

struct node* findIntersection(struct node* head1, struct node* head2)
{
    struct node *head=NULL;
    int hash[1001]={0};
    struct node *p=head1;
    struct node *q=head2;
    while(p!=NULL)
    {
  	    hash[p->data]++;
  	    p=p->next;
    }
    while(q!=NULL){
        if(hash[q->data])
        {
	        hash[q->data]--;
            head=insert(head,q->data);
        }
        q=q->next;
    }
  return head;
}

