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

Node *pruneWithPathSumLessThanK(Node *root,int k,int *sum){
	if(root==NULL)return NULL;
	
	int lsum=*sum+root->data;
	int rsum=lsum;
	
	root->left=pruneWithPathSumLessThanK(root->left,k,&lsum);
	root->right=pruneWithPathSumLessThanK(root->right,k,&rsum);
	
	*sum=max(lsum,rsum);
	
	if(*sum<k){
		free(root);
		return NULL;
	}
	
	return root;
}

void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

int main(){
	int k = 45;
	int sum = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);
    Node *temp=pruneWithPathSumLessThanK(root,k,&sum);
    print(temp);
}
