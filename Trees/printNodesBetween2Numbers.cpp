#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void printNodesBetween2Numbers(Node *root,int a,int b){
	if(root==NULL)return;
	queue<Node *> q;
	
	q.push(root);
	q.push(NULL);
	int count=1;
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		
		if(!temp){
			count++;
			q.push(NULL);
			if(count>b)break;
			if(count>=a && count<=b)cout<<endl;
		}
		else{
			if(count>=a && count<=b)
				cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}


int main()
{
	Node* root=new Node(20);
	root->left=new Node(8);
	root->left->left=new Node(4);
	root->left->right=new Node(12);
	root->right=new Node(22);
	root->left->right->left=new Node(10);
	root->left->right->right=new Node(14);
	printNodesBetween2Numbers(root,2,4);
	return 0;
}

