#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void push(struct node** head_ref, int new_data)
{
 
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}


struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);

  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

int main()
{
   
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    res = SortedMerge(a, b);
    printList(res);
 
    return 0;
}
