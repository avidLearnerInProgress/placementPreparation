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


Node *findLCAUtil(Node *root,int n1,int n2,bool &v1,bool &v2){
	if(root==NULL)return NULL;
	if(root->data==n1){
		v1=true;
		return root;
	}
	if(root->data==n2){
		v2=true;
		return root;
	}
	
	Node *lca=findLCAUtil(root->left,n1,n2,v1,v2);
	Node *rca=findLCAUtil(root->right,n1,n2,v1,v2);
	if(lca && rca)return root;
	
	return(lca!=NULL)?lca:rca;
}

bool find(Node *root,int key){
	if(root==NULL)return false;
	if(root->data==key||find(root->left,key)||find(root->right,key))return true;
	
	return false;
}

Node *findLCA(Node *root,int n1,int n2){
	if(root==NULL)return NULL;
	
	bool v1=true;
	bool v2=true;
	
	Node *lca=findLCAUtil(root,n1,n2,v1,v2);
	if(v1 && v2 || v1 && find(lca,n2) || v1 && find(lca,n1))
		return lca;
	
	return NULL;
}

int main()
{
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *lca =  findLCA(root, 4, 5);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->data;
    else
       cout << "Keys are not present ";
 
    lca =  findLCA(root, 4, 10);
    if (lca != NULL)
       cout << "\nLCA(4, 10) = " << lca->data;
    else
       cout << "\nKeys are not present ";
 
    return 0;
}

