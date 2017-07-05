/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node *mergeIncreasing(Node *head1,Node *head2){
    Node *a=head1;
    Node *b=head2;
    Node *result;
        
    if(a==NULL)return b;
    
    if(b==NULL)return a;
    
    if(a->data>=b->data){
        result=b;
        result->next=mergeIncreasing(a,b->next);
    }
    
    else{
        result=a;
        result->next=mergeIncreasing(a->next,b);
    }
    
    return result;
}

struct Node * mergeResult(Node *head1,Node *head2)
{
    Node *current=mergeIncreasing(head1,head2);
    Node *head=current;
    Node *prev=NULL;
    Node *next;
    
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    return prev;
  // Your Code Here
    
}
