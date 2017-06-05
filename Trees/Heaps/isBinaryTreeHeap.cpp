#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};


bool isHeap(Node *root){
	if(!root)return true;
	
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		
		if(temp->left){
			if(temp->data<temp->left->data)return false;
			q.push(temp->left);
			
		}
		
		if(temp->right){
			if(temp->data<temp->right->data)return false;
			q.push(temp->right);
		}
		
	}
	return true;
}


int main()
{
	 Node* root = NULL;
    root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);
	if(isHeap(root))
		cout<<"It's a heap"<<endl;
	else
		cout<<"It's not a heap"<<endl;
	return 0;
}

