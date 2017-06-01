#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node*left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

int search(int arr[],int start,int end,int value){
	for(int i=start;i<=end;i++)
		if(arr[i]==value)
			return i;
	return -1;
}

int *extractKeys(int in[],int level[],int m,int n){
	int *newLevel=new int[m];
	int j=0;
	
	for(int i=0;i<n;i++){
		if(search(in,0,m-1,level[i])!=-1){
			newLevel[j]=level[i];
			j++;
		}
	}
	return newLevel;
}

Node *constructTree(int in[],int level[],int start,int end,int n){
	if(start>end)return NULL;
	Node *root=new Node(level[0]);
	
	if(start==end)return root;
	
	int inIndex=search(in,start,end,root->data);
	
	int *leftLevel=extractKeys(in,level,inIndex,n);
	int *rightLevel=extractKeys(in+inIndex+1,level,n-inIndex-1,n);
	
	root->left=constructTree(in,leftLevel,start,inIndex-1,n);
	root->right=constructTree(in,rightLevel,inIndex+1,end,n);
	
	delete []leftLevel;
	delete []rightLevel;
	
	return root;
}

void printInorder(Node* node)
{
    if (!node)return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}


int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = constructTree(in, level, 0, n - 1, n);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
    return 0;
}
