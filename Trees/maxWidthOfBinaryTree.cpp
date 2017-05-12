#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right;
	
	Node(int x){
		data=x;
	}
};

int maxWidthOfBinaryTree(Node *root){
	if(root==NULL)return 0;
	queue<Node *> q;
	int result=0;
	
	q.push(root);
	while(!q.empty()){
		
		int count=q.size();
		result=max(count,result);
		
		while(count--){
			Node *temp=q.front();
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		
	}
	return result;
}


int main(){
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->left->left=new Node(7);
	root->right->left->right=new Node(8);
	
	cout<<maxWidthOfBinaryTree(root)<<endl;
	
	
}
