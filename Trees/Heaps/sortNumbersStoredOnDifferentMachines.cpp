#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node *next;
};

Node *insert(int x){
	Node *temp=new Node;
	temp->data=x;
	temp->next=NULL;
	
	return temp;
	
}


Node *push(Node *head,int x){
	Node *temp=new Node;
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}

/*

bool operator>(const Node &a,const Node &b){
	return a->data>b->data;
}
*/

struct cmp
{
	bool operator()(Node *A,Node *B)
	{
		return A->data > B->data;
	}
};


void print(Node *a){
	while(a){
		cout<<a->data<<" ";
		a=a->next;
	}
}

void externalSort(Node *arr[],int n){
	
	priority_queue<Node *,vector<Node *>,cmp> pq;
	Node *dummy=insert(0);
	Node *tail=dummy;
	for(int i=0;i<n;i++){
		if(arr[i])pq.push(arr[i]);
	}
	
	while(!pq.empty()){
		tail->next=pq.top();
		tail=tail->next;
		pq.pop();
		
		if(tail->next)pq.push(tail->next);
		
	}
	print(dummy->next);
}

int main(){
	int n = 3;
	Node *A[n];
	A[0] = NULL;
	A[0] = push(A[0],50);
	A[0] = push(A[0],40);
	A[0] = push(A[0],30);
 
	A[1] = NULL;
	A[1] = push(A[1],45);
	A[1] = push(A[1],35);
 
	A[2] = NULL;
	A[2] = push(A[2],100);
	A[2] = push(A[2],80);
	A[2] = push(A[2],70);
	A[2] = push(A[2],60);
	A[2] = push(A[2],10);
 
	externalSort(A,n);
 
	return 0;
}
