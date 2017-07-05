/* The structure of the Linked list Node is as follows:
struct Node {
    int val;
    struct Node* next;
}; */

void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    if(*head1==NULL || *head2 == NULL) 
    {
        *head3=NULL;
        return;
    }
    
    if((*head1)->val == (*head2)->val)
    {
        Node * temp = new Node;
        temp->val = (*head1)->val;
        temp->next = NULL;
        if(*head3==NULL)
            *head3 = temp;
        else
            (*head3)->next = temp;
            
        intersection(&((*head1)->next),&((*head2)->next),&((*head3)->next));
    }
    else if((*head1)->val > (*head2)->val)
    {
        intersection(head1,&((*head2)->next),head3);
    }
    else
    {
        intersection(&((*head1)->next),head2,head3);
    }
}
