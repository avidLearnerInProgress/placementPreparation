#include<bits/stdc++.h>

using namespace std;


struct node {
	int data;
	struct node *next;
};

int getCount(struct node *head){
	struct node *temp=head;int count=0;
	while(temp){
		
		temp=temp->next;
		count++;
		
	}
	return count;
}

int __getIntersectionNodeData(int d,struct node *head1,struct node *head2){
	
	struct node *curr1=head1;
	struct node *curr2=head2;
	
	for(int i=0;i<d;i++){
		if(curr1==NULL)
			return -1;
			
		curr1=curr1->next;
	}	
	
	while(curr1 !=NULL && curr2!=NULL )
	{
		if(curr1==curr2) return curr1->data;
		
		curr1=curr1->next;
		curr2=curr2->next;
	}
		return -1;
		
}




int getIntersectionNode(struct node *head1,struct node *head2){
	int c1=getCount(head1);
	int c2=getCount(head2);
	int d;
	if(c1>c2){
		d=c1-c2;
		return __getIntersectionNodeData(d,head1,head2);
		
	}
	
	else if(c2>c1){
		d=c2-c1;
		return __getIntersectionNodeData(d,head2,head1);
	}
	
}

int main()
{

 
  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntersectionNode(head1, head2));
 
  getchar();
}
