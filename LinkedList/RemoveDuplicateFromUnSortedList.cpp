#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


struct Node *newNode(int data)
{
   Node *temp = new Node;
   temp->data = data;
   temp->next = NULL;
   return temp;
}


void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void removeDuplicates(struct Node *start){
	
	unordered_set<int> s;
	
	struct Node *curr=start;
	struct Node *prev=NULL;
	
	while(curr!=NULL){
		if(s.find(curr->data)!=s.end()){
			prev->next=curr->next;
			delete(curr);
		}
		else
		{
			s.insert(curr->data);
			prev=curr;
			
		}
		curr=prev->next;
	}
}



int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =
                                    newNode(11);
    start->next->next->next->next->next->next =
                                    newNode(10);
 
    printf("Linked list before removing duplicates : \n");
    printList(start);
 
    removeDuplicates(start);
 
    printf("\nLinked list after removing duplicates : \n");
    printList(start);
 
    return 0;
}
