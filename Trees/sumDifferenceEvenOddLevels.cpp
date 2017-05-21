#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};


int sumDifferenceEvenOddLevels(Node *root){
	if(!root)return 0;
	
	else
	return root->data-sumDifferenceEvenOddLevels(root->left)-sumDifferenceEvenOddLevels(root->right);
}

int main(){
	Node *root=new Node(5);
	 root->left = new Node(2);
    root->right = new Node(6);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(7);
    
    cout<<sumDifferenceEvenOddLevels(root)<<endl;
}
