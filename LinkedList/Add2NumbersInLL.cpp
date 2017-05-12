#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void addTwoLists (struct Node* first, struct Node* second){
	struct Node *add1=first;
    struct Node *add2=second;
   	vector<int> v1;
   	vector<int> v2;
    while(add1!=NULL)   
    {
        v1.push_back(add1->data);
        add1=add1->next;
    }
    
    while(add2!=NULL)   
    {
        v2.push_back(add2->data);
        add2=add2->next;
    }
    
    transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), plus<int>());
    reverse(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++)
        cout<<v1[i];
    cout<<endl;
    return;
}



struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}


void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
        cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    	push(&second, x);
	    }
	 addTwoLists(first, second);
	   // 
	freeList(first);
	freeList(second);
	freeList(res);
   
   }
   return 0;
}

