#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	
}Node;

bool isRootToLeafSumEqualToGivenSum(Node *root,int sum){
	if(root==NULL)return (sum==0);
	else{
		
		int ans=0;
		int subsum=sum-root->data;
		if(subsum==0 && root->left==NULL && root->right==NULL)return 1;
		if(root->left)
			ans=ans||isRootToLeafSumEqualToGivenSum(root->left,subsum);
		if(root->right)	
			ans=ans||isRootToLeafSumEqualToGivenSum(root->right,subsum);
		
		return ans;	
		
	}
	
	
	
}

Node *createNode(int data){
	
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}



int main(){
	int sum = 21;
	Node *root=createNode(10);
	root->left=createNode(8);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right->left=createNode(2);
	cout<<isRootToLeafSumEqualToGivenSum(root,sum)<<endl;
		
		
}
