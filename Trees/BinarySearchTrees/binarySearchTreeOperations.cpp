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


Node *searchBST(Node *root,int key){
	if(root==NULL)return root;
	
	if(root->data==key)return root;
	
	if(key>root->data)
		return searchBST(root->right,key);

	
	if(key<root->data)
		return searchBST(root->left,key);
	
}


Node *insertBST(Node *root,int key){
	if(root==NULL){
		Node *temp=new Node(key);
		return temp;
	}
	
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	if(key>root->data){
		root->right=insertBST(root->right,key);
	}
	return root;
}

Node *getMinNode(Node *root){
	Node *current=root;
	while(current->left!=NULL)current=current->left;
	
	return current;
}

Node *deleteBST(Node *root,int key){
	if(root==NULL)return root;
	
	if(key<root->data){
		root->left=deleteBST(root->left,key);
	}
	else if(key>root->data){
		root->right=deleteBST(root->right,key);
	}
	
	else{
		if(root->left==NULL){
			Node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp=root->left;
			free(root);
			return temp;
		}
		
		else{
			Node *temp=getMinNode(root->right);
			root->data=temp->data;
			root->right = deleteBST(root->right, temp->data);
			
		}
		
		
	}
	
	return root;
}


void print(Node *root){
	if(root){
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
	}
}

int main(){
	Node *root=NULL;
	root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    print(root);
	Node*found=searchBST(root,90);
	cout<<endl;
	if(found)cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
	
	root=deleteBST(root, 30);
	print(root);
	found=searchBST(root,30);
	cout<<endl;
	if(found)cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
	
	
}

