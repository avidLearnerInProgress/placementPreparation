Node * copyList(Node *head)
{
     // Your code here
     Node *x,*y;
     map<Node *,Node *> mp;
     x=head;
     
     while(x){
         
         y=newNode(x->data);
         mp.insert(make_pair(x,y));
         x=x->next;
     }
     x=head;
     map<Node *,Node *>::iterator it;
    
     while(x){
         it=mp.find(x);
         y=it->second;
         it=mp.find(x->next);
         y->next=it->second;
         it=mp.find(x->arb);
         y->arb=it->second;
         x=x->next;
     }
     
     y->next=NULL;
     x=head;
     it=mp.find(x);
     return it->second;
      
     
}
