#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
	}
	
};


bool isIdentical(Node *a,Node *b){
	if(a==NULL && b==NULL)return 1;
	if(a==NULL || b==NULL)return 0;
	
	return((a->data==b->data)&&isIdentical(a->left,b->left)&&isIdentical(a->right,b->right));
}


bool isSubTree(Node *T,Node *S){
	
	if(S==NULL)return true;
	if(T==NULL)return false;
	
	if(isIdentical(T,S))return true;
	return(isSubTree(T->left,S) || isSubTree(T->right,S));
	
}

int main(){
	
	Node *T = new Node(26);
    T->right = new Node(3);
    T->right->right = new Node(3);
    T->left = new Node(10);
    T->left->left = new Node(4);
    T->left->left->right = new Node(30);
    T->left->right = new Node(6);
    
    Node *S=new Node(10);
    S->right = new Node(6);
    S->left = new Node(4);
    S->left->right = new Node(30);
    
    if(isSubTree(T,S))cout<<"1"<<endl;
    else
    	cout<<"0"<<endl;
   
}
