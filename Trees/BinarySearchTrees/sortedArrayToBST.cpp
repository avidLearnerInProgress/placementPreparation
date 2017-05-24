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

void printInOrder(Node *root){
	if(!root)return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}

Node *sortedArrayToBST(int arr[],int start,int end){
	
	if(start>end)return NULL;
	int mid=(start+end)/2;
	
	Node *temp=new Node(arr[mid]);
	
	temp->left=sortedArrayToBST(arr,start,mid-1);
	temp->right=sortedArrayToBST(arr,mid+1,end);
	
	return temp;
	
}

int main(void)
{
    Node* root=NULL;
    int arr[]={7,6,5,4,3,2,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    root=sortedArrayToBST(arr,0,n-1);
    printInOrder(root);
 
    return 0;
}
