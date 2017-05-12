#include<bits/stdc++.h> 
using namespace std;

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *down;
} Node;
 

void push(Node** head_ref, int new_data)
{

    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->right = NULL;
    new_node->data  = new_data;
    new_node->down = (*head_ref);
    (*head_ref)    = new_node;
}
 
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->down;
    }
}
 
Node* merge(Node* a,Node* b) 
{
	Node* res;
	if(a==NULL)	return b;
    if(b==NULL) return a;
	
		if(a->data < b->data){
			res=a;
			res->down=merge(a->down,b);
		}
		else{
			res=b;
			res->down=merge(a,b->down);
			
		}
	return res;
}
 
Node* flattenLL(Node* head){
	
	if(head==NULL || head->right==NULL)
		return head;	
	return merge(head,flattenLL(head->right));
}


int main()
{
    Node* root = NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );
 
    push( &( root->right ), 20 );
    push( &( root->right ), 10 );
 
    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );
 
    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    root = flattenLL(root);
    printList(root);
 
    return 0;
}
