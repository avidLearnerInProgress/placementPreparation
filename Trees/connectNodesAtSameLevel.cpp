#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right,*nextRight;
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
		nextRight=NULL;
		
	}
};

void connectNodesAtSameLevel(Node *root){       //Iterative
	if(root==NULL)return ;
	
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		
		while(size--){
			Node *popped=q.front();
			q.pop();
			cout<<popped->data<<" -> ";
			if(size){
				popped->nextRight=q.front();
				cout<<popped->nextRight->data<<endl;
			}	
			else{
				popped->nextRight=NULL;
				cout<<"-1"<<endl;
			}
			if(popped->left)
				q.push(popped->left);
			if(popped->right)	
				q.push(popped->right);
		
		}
	}

}

void connectRecur(Node *root){   
	
	if(!root)return;
	if(root->left){
		root->left->nextRight=root->right;
		cout<<root->left->data<<" -> "<<root->left->nextRight->data<<endl;
	}
	if(root->right){	
		root->right->nextRight=(root->nextRight)?(root->nextRight->left):(NULL);
		if(root->right->nextRight)
			cout<<root->right->data<<" -> "<<root->right->nextRight->data<<endl;
		else
			cout<<root->right->data<<" -> "<<"-1"<<endl;
	}
	connectRecur(root->left);
	connectRecur(root->right);
	
}

void _connectNodesAtSameLevel(Node *root){   //Recursive
	root->nextRight=NULL;
	cout<<root->data<<" -> "<<-1<<endl;
	connectRecur(root);
}


int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);

	connectNodesAtSameLevel(root);
	cout<<endl;
	_connectNodesAtSameLevel(root);

}
