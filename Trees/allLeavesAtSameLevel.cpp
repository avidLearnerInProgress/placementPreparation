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

bool allLeavesAtSameLevel(Node *root,int level,int *max_level){
	if(root==NULL)return true;
	if(root->left==NULL && root->right==NULL){
		
		if(*max_level==0){
			*max_level=level;
			return true;
		}
		return(level==*max_level);
	}
	return allLeavesAtSameLevel(root->left,level+1,max_level)&&allLeavesAtSameLevel(root->right,level+1,max_level);
	
}



int main(){
	
	Node *root=new Node(12);
	 root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(1);
	int level=0;
	int max_level=0;
	cout<<allLeavesAtSameLevel(root,level,&max_level)<<endl;
	
}
