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

void inOrderPredecessorSuccessor(Node *root,int key,Node *&pre,Node *&suc){
	if(root==NULL)return;
	
	if(root->data==key){
		
		if(root->left!=NULL){
			Node *temp=root->left;
			while(temp->right)
				temp=temp->right;
			pre=temp;
		
		}
		if(root->right!=NULL){
			Node *temp=root->right;
			while(temp->left)
				temp=temp->left;
			suc=temp;	
		}
		return;
	}
	else
	{
		if(key<root->data){
			suc=root;
			inOrderPredecessorSuccessor(root->left,key,pre,suc);
		}
		if(key>root->data){
			pre=root;
			inOrderPredecessorSuccessor(root->right,key,pre,suc);
		}
	}

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
/* Iterative GFG
struct node *lca(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
         // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
           root = root->left;
 
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
           root = root->right;
 
        else break;
    }
    return root;
}
*/

int main(){
	Node *root=NULL;
	root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    int key=70;
    Node *pre=NULL;
    Node *suc=NULL;
    inOrderPredecessorSuccessor(root,key,pre,suc);
     if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    
	
}
