#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void append(struct node** headRef, int newData)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}

void printList(struct node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
} 


void alternatingSplitList(struct node* head, struct node** a, struct node** b)
{
    // Code here
    if(!head)return;
    if(!head->next){*a=head;return;}
    
    *a=head;
    *b=head->next;
    
    node *_a=*a;
    node *_b=*b;
    
    while(_a!=NULL && _b!=NULL){
        if(_a->next)_a->next=_a->next->next;
        
        if(_b->next)_b->next=_b->next->next;
        
        _a=_a->next;
        _b=_b->next;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--)
    {
        struct node* head = NULL;
        struct node* a = NULL;
        struct node* b = NULL;
        int n, k;
        cin>>n;
        while(n--)
        {
            cin>>k;
            append(&head, k);
        }
        alternatingSplitList(head, &a, &b);
        printList(a);
        printList(b);
    }
    return 0;
}

