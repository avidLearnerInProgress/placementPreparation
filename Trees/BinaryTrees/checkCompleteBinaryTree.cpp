#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	
	Node(int x){
		data=x;
	}
};

bool checkCompleteBinaryTree(Node *p){
	
	if(!p)return true;
	
	bool flag=false;
	
	queue<Node *> q;
	q.push(p);
	
	while(!q.empty()){
		
		Node *temp=q.front();
		q.pop();
		
		if(temp->left){
			if(flag==true)return false;
			
			q.push(temp->left);
		}
		
		else flag=true;
		
		if(temp->right){
			if(flag==true)return false;
			
			q.push(temp->right);
		}
		
		else flag=true;
		
	}
	
	return true;
	
}

int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right= new Node(7);
	
	if(checkCompleteBinaryTree(root))cout<<1<<endl;
	else cout<<0<<endl;
	
	
	
	
}
