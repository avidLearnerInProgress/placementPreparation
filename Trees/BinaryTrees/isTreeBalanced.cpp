#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	
}Node;

Node *createNode(int data){
	
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

int heightOfTree(Node *a){ 
	
//height= max depth
//height we measure from root (1/0) to leaf (nth height)
//depth we measure from leaf (nth depth) to root(0)
	if(a==NULL)return 0;
	else return (1+ max(heightOfTree(a->left),heightOfTree(a->right)));
	
}

bool isTreeBalanced(Node *root){
	
	if(root==NULL)return 1;
	int lh=heightOfTree(root->left);
	int rh=heightOfTree(root->right);
	if((abs(lh-rh)<=1) && isTreeBalanced(root->left) && isTreeBalanced(root->right)) return 1;
	else return 0;
	
}

bool _isTreeBalanced(Node *root,int *h){ //calculate height on the fly optimized version O(n)

	if(root==NULL){
		*h=0;return 1;
	}
	int lh=0,rh=0;
	int l=0,r=0;
	
	l=_isTreeBalanced(root->left,&lh);
	r=_isTreeBalanced(root->right,&rh);
	
	*h=abs(lh-rh)+1;
	
	if(abs(lh-rh)>=2)return 0;
	
	else return l&&r;
	
}



int main(){
		Node *root1=createNode(1);
		root1->left=createNode(2);
		root1->right=createNode(3);
		root1->left->left=createNode(4);
		root1->left->right=createNode(5);
		root1->right->left=createNode(6);
		root1->right->right=createNode(7);
		cout<<isTreeBalanced(root1)<<endl;
		int height=0;
		cout<<_isTreeBalanced(root1,&height)<<endl;
		
}
